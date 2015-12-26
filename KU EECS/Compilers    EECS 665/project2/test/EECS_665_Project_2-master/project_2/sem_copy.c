# include <stdio.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"

extern int formalnum;
extern char formaltypes[];
extern int localnum;
extern char localtypes[];
extern int localwidths[];

int numlabels = 0;                      /* total labels in file */
int numblabels = 0;                     /* toal backpatch labels in file */

//int lastlabel = -1;
int blockdepth = 0;

int from_rel = 0;

typedef struct s {
	struct sem_rec *top;
	struct sem_rec *bottom;
} Scope;


// Max scope depth
#define MAX_DEPTH 50

// Array of semantic records for each scope level.
//  Initialized in startlookscope().
Scope **scopes = NULL;
Scope *currscope = NULL;

/*
 * backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
	// Print the label this branch should branch to and
	//  store it in s_place.
	for( ; p; p =p->back.s_link) {
		printf("B%i=L%i\n", p->s_place, k);
		p->s_place = k;
	}
}

/*
 * bgnstmt - encountered the beginning of a statement
 */
void bgnstmt()
{
  extern int lineno;

  //lineno++;

  printf("bgnstmt %d\n", lineno);
}


/*
 * call - procedure invocation
 */
struct sem_rec *call(char *f, struct sem_rec *args)
{
	struct id_entry *id_t = lookup(f, 0);

	// If the function hasn't been defined, we need to install it.
	if(!id_t) {
		id_t = install(f, 0);
		id_t->i_scope = GLOBAL;
		id_t->i_type = T_PROC;
	}

	// Output list of args and counter them.
	int num_args = 0;
	for( ; args; args = args->back.s_link) {
		gen("args", NULL, args, args->s_mode);
		num_args++;
	}

	struct sem_rec *node_t = node(
		num_args,
		0,
		NULL,
		NULL
	);

	return gen(
		"f",
		id(f),
		node_t,
		id_t->i_type
	);
}

/*
 * ccand - logical and
 */
struct sem_rec *ccand(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	backpatch(e1->back.s_true, m);
	struct sem_rec *merged = merge(
		e1->back.s_true,
		e1->back.s_true
	);
	struct sem_rec *ret_val = node(0, 0, e2->back.s_true, merged);

	return ret_val;
}

/*
 * ccexpr - convert arithmetic expression to logical expression
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
	// from_rel is only set to 1 in rel().
	if(!from_rel) {
   		e = gen("!=", e, cast(con("0"), e->s_mode), e->s_mode);
	}

	from_rel = 0;

   printf("bt t%d B%d\n", e->s_place, ++numblabels);
   printf("br B%d\n", ++numblabels);
   return (node(0, 0,
                node(numblabels-1, 0, (struct sem_rec *) NULL,
                     (struct sem_rec *) NULL),
                node(numblabels, 0, (struct sem_rec *) NULL,
                     (struct sem_rec *) NULL)));
}

/*
 * ccnot - logical not
 */
struct sem_rec *ccnot(struct sem_rec *e)
{
	struct sem_rec *ret_val = node(0, 0, e->s_false, e->back.s_true);
	return ret_val;
}

/*
 * ccor - logical or
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
	// same as ccand() but we backpatch on false.
	backpatch(e1->s_false, m);
	struct sem_rec *merged = merge(
		e1->back.s_true,
		e1->back.s_true
	);
	struct sem_rec *ret_val = node(0, 0, merged, e2->s_false);

	return ret_val;
}

/*
 * con - constant reference in an expression
 */
struct sem_rec *con(char *x)
{
  struct id_entry *p;

  if((p = lookup(x, 0)) == NULL) {
    p = install(x, 0);
    p->i_type = T_INT;
    p->i_scope = GLOBAL;
    p->i_defined = 1;
  }

  /* print the quad t%d = const */
  printf("t%d := %s\n", nexttemp(), x);

  /* construct a new node corresponding to this constant generation
     into a temporary. This will allow this temporary to be referenced
     in an expression later*/
  return(node(currtemp(), p->i_type, (struct sem_rec *) NULL,
	      (struct sem_rec *) NULL));
}

/*
 * dobreak - break statement
 */
void dobreak()
{
	// leave this scope
	currscope->top = merge(
		currscope->bottom,
		n()
	);
}

/*
 * docontinue - continue statement
 */
void docontinue()
{
	// stay in scope
	currscope->top = merge(
		currscope->top,
		n()
	);
}

/*
 * dodo - do statement
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{
	backpatch(e->back.s_true,m1);
	backpatch(e->s_false, m3);
	backpatch(currscope->top, m2);

	endloopscope(m3);
}

/*
 * dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
           int m3, struct sem_rec *n2, int m4)
{
	if(e2) {
		backpatch(e2->back.s_true, m3);
		backpatch(e2->s_false, m4);

		//endloopscope(m4);
	}

	backpatch(currscope->top, m2);
	backpatch(n1, m1);
	backpatch(n2, m2);

	endloopscope(m4);
}

/*
 * dogoto - goto statement
 */
void dogoto(char *id)
{
   fprintf(stderr, "sem: dogoto not implemented\n");
}

/*
 * doif - one-arm if statement
 */
void doif(struct sem_rec *e, int m1, int m2)
{
	//Note: e isn't needed.
	backpatch(e->back.s_true, m1);
	backpatch(e->s_false, m2);
}

/*
 * doifelse - if then else statement
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
                         int m2, int m3)
{
	//Note: e isn't needed.
	backpatch(e->back.s_true, m1);
	backpatch(e->s_false, m2);
	backpatch(n, m3);
}

/*
 * doret - return statement
 */
void doret(struct sem_rec *e)
{
	// Note: e is not needed.
	if(T_INT == e->s_mode) {
		printf("reti t%i\n", currtemp());
	}
	else if(T_DOUBLE == e->s_mode) {
		printf("retf t%i\n", currtemp());
	}

	// yay, no backpatching
}

/*
 * dowhile - while statement
 */
void dowhile(int m1, struct sem_rec *e, int m2, struct sem_rec *n,
             int m3)
{
	// Note: e isn't needed.
	startloopscope();

	backpatch(e->back.s_true, m2);
	backpatch(e->s_false, m3);
	backpatch(n, m1);

	endloopscope(m3);
}

/*
 * endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
	backpatch(currscope->bottom, m);

	currscope = scopes[--blockdepth - 1];
}

/*
 * exprs - form a list of expressions
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
	// Get the last record in the list.
	for( ; l; l = l->back.s_true);

	l->back.s_true = e;

	return l;
}

/*
 * fhead - beginning of function body
 */
void fhead(struct id_entry *p)
{
	int i;
	for(i = 0; i < formalnum; i++) {
		if(formaltypes[i] == 'i') {
			printf("formal 4\n");
		}
		else if(formaltypes[i] == 'f') {
			printf("formal 8\n");
		}
	}

	for(i = 0; i < localnum; i++) {
		if(localtypes[i] == 'i') {
			printf("localloc%i\n", 4 * localwidths[i]);
		}
		else if(localtypes[i] == 'f') {
			printf("localloc%i\n", 4 * localwidths[i]);
		}
	}
}

/*
 * fname - function declaration
 */
struct id_entry *fname(int t, char *id)
{
	struct id_entry *id_t = lookup(id, 0);

	// If the id doesn't exist yet, install it.
	if(!id_t) {
		id_t = install(id, 0);
	}

	id_t->i_scope = GLOBAL;
	id_t->i_type = t|T_PROC;

	enterblock();
	formalnum = 0;

	printf("func %s\n", id);

	return id_t;
}

/*
 * ftail - end of function body
 */
void ftail()
{
	leaveblock();
	leaveblock();

	printf("fend\n");
}

/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{
   struct id_entry *p;

   if ((p = lookup(x, 0)) == NULL) {
      yyerror("undeclared identifier");
      p = install(x, -1);
      p->i_type = T_INT;
      p->i_scope = LOCAL;
      p->i_defined = 1;
   }
   if (p->i_scope == GLOBAL)
      printf("t%d := global %s\n", nexttemp(), x);
   else if (p->i_scope == LOCAL)
      printf("t%d := local %d\n", nexttemp(), p->i_offset);
   else if (p->i_scope == PARAM) {
      printf("t%d := param %d\n", nexttemp(), p->i_offset);
      if (p->i_type & T_ARRAY) {
         (void) nexttemp();
         printf("t%d := @i t%d\n", currtemp(), currtemp()-1);
      }
   }

   /* add the T_ADDR to know that it is still an address */
   return (node(currtemp(), p->i_type|T_ADDR, (struct sem_rec *) NULL,
                (struct sem_rec *) NULL));
}

/*
 * index - subscript
 */
struct sem_rec *tom_index(struct sem_rec *x, struct sem_rec *i)
{

  return (gen("[]", x, cast(i, T_INT), x->s_mode&~(T_ARRAY)));

  /* generate a quad t%d = x [] i */
  //printf("t%d := ", nexttemp());
  //printf("t%d ", x->s_place);
  //if(x->s_mode & T_INT)
  //  printf("[]i ");
  //else
  //  printf("[]f ");
  //printf("t%d\n", i->s_place);

  /* create a new node for the index operation. No links to backpatch */
  //return (node(currtemp(), (x->s_mode & ~(T_ARRAY)),
  //	       (struct sem_rec *)NULL, (struct sem_rec *)NULL));
}

/*
 * labeldcl - process a label declaration
 */
void labeldcl(char *id)
{
	install(id, 0);
}

/*
 * m - generate label and return next temporary number
 */
int m()
{
	numlabels++;
	printf("label L%i\n", numlabels);
	return numlabels;
}

/*
 * n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
	//increment labels so duplicate labels can't occur.
	numlabels++;
	printf("br B%i\n", numlabels);
	return node(numlabels, 0, NULL, NULL);
}

/*
 * op1 - unary operators
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{
  if (*op == '@' && !(y->s_mode&T_ARRAY)){
    /* get rid of T_ADDR if it is being dereferenced so can handle
       T_DOUBLE types correctly */
    y->s_mode &= ~T_ADDR;
    return (gen(op, (struct sem_rec *) NULL, y, y->s_mode));
  }
  else{
    fprintf(stderr, "sem: op1 not implemented\n");
    return ((struct sem_rec *) NULL);
  }
}

/*
 * op2 - arithmetic operators
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
	// This function is basically a wrapper for gen() that
	//  determines the right type between T_INT and T_DOUBLE.
	int type = T_INT;

	if(T_DOUBLE == x->s_mode || T_DOUBLE == y->s_mode) {
		type = T_DOUBLE;
	}

	return gen(
		op,
		cast(x, type),
		cast(y, type),
		type
	);
}

/*
 * opb - bitwise operators
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
	return gen(
		op,
		cast(x, T_INT),
		cast(y, T_INT),
		T_INT
	);
}

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
	// This function is basically a wrapper for gen() that
	//  determines the right type between T_INT and T_DOUBLE.
	int type = T_INT;

	if(T_DOUBLE == x->s_mode || T_DOUBLE == y->s_mode) {
		type = T_DOUBLE;
	}

	struct sem_rec *p = gen(
		op,
		cast(x, type),
		cast(y, type),
		type
	);

	from_rel = 1;
	return ccexpr(p);
}


/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
  /* assign the value of expression y to the lval x */
  struct sem_rec *p, *cast_y;

	if( *op != '\0' || x == NULL || y == NULL ) {
	  	if(*op == '<' || *op == '>' || *op == '^' || *op == '&' || *op == '|'){
			struct sem_rec* p1 = gen(
				"@",
				NULL,
				x,
				x->s_mode & ~T_ADDR
			);

			struct sem_rec *p2 = gen(
				op,
				cast(cast(p1, T_INT), T_INT),
				cast(y, T_INT),
				T_INT
			);

			p = cast(p2, x->s_mode);
		} else {
			p = gen(
				op,
				gen("@", NULL, x, x->s_mode),
				cast(y, x->s_mode),
				x->s_mode
			);
		}
  }

  /* if for type consistency of x and y */
  cast_y = p;
  if((x->s_mode & T_DOUBLE) && !(y->s_mode & T_DOUBLE)){

    /*cast y to a double*/
    printf("t%d = cvf t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_DOUBLE, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }
  else if((x->s_mode & T_INT) && !(y->s_mode & T_INT)){

    /*convert y to integer*/
    printf("t%d = cvi t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_INT, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }

  /*output quad for assignment*/
  if(x->s_mode & T_DOUBLE)
    printf("t%d := t%d =f t%d\n", nexttemp(),
	   x->s_place, cast_y->s_place);
  else
    printf("t%d := t%d =i t%d\n", nexttemp(),
	   x->s_place, cast_y->s_place);

  /*create a new node to allow just created temporary to be referenced later */
  return(node(currtemp(), (x->s_mode&~(T_ARRAY)),
	      (struct sem_rec *)NULL, (struct sem_rec *)NULL));
}

/*
 * startloopscope - start the scope for a loop
 */
void startloopscope()
{
	// Lazy initalization. This will be a problem if the program
	//  becomes threaded.
	if(!scopes){
		scopes = (Scope **)malloc(MAX_DEPTH * sizeof(Scope));
		memset(scopes, 0, MAX_DEPTH * sizeof(Scope));

		int i;
		for(i = 0; i < MAX_DEPTH; i++) {
			scopes[i] = (Scope *)malloc(sizeof(Scope));
		}

		currscope = scopes[0];
	}

	currscope = scopes[blockdepth++];

	// Segmentation faults are bad.
	currscope->top = NULL;
	currscope->bottom = NULL;
}

/*
 * string - generate code for a string
 */
struct sem_rec *string(char *s)
{
	printf("t%i := %s\n", nexttemp(), s);

	struct sem_rec *node_t = node(
		currtemp(),
		T_STR,
		NULL,
		NULL
	);

	node_t->s_mode = T_STR;

	return node_t;
}



/************* Helper Functions **************/

/*
 * cast - force conversion of datum y to type t
 */
struct sem_rec *cast(struct sem_rec *y, int t)
{
   if (t == T_DOUBLE && y->s_mode != T_DOUBLE)
      return (gen("cv", (struct sem_rec *) NULL, y, t));
   else if (t != T_DOUBLE && y->s_mode == T_DOUBLE)
      return (gen("cv", (struct sem_rec *) NULL, y, t));
   else
      return (y);
}

/*
 * gen - generate and return quadruple "z := x op y"
 */
struct sem_rec *gen(char *op, struct sem_rec *x, struct sem_rec *y, int t)
{
   if (strncmp(op, "arg", 3) != 0 && strncmp(op, "ret", 3) != 0)
      printf("t%d := ", nexttemp());
   if (x != NULL && *op != 'f')
      printf("t%d ", x->s_place);
   printf("%s", op);
   if (t & T_DOUBLE && (!(t & T_ADDR) || (*op == '[' && *(op+1) == ']'))) {
      printf("f");
      if (*op == '%')
         yyerror("cannot %% floating-point values");
   }
   else
      printf("i");
   if (x != NULL && *op == 'f')
      printf(" t%d %d", x->s_place, y->s_place);
   else if (y != NULL)
      printf(" t%d", y->s_place);
   printf("\n");
   return (node(currtemp(), t, (struct sem_rec *) NULL,
           (struct sem_rec *) NULL));
}
