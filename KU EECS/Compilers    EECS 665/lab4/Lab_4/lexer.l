%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define the tokens that you want to return from your lex as follows
#define ID 256
#define INTVAL 257
#define UNSIGNED 258
#define TYPEDEF 259
#define STRUCT 260
#define CONST 261
#define STATIC 262 
#define EXTERN 263
#define AUTO 264
#define REGISTER 265
#define SIZEOF 266
#define RETURN 267
#define DO 268
#define WHILE 269
#define FOR 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define IF 274
#define ELSE 275
#define CONTINUE 276
#define BREAK 277
#define GOTO 278
#define EQ 279
#define NE 280
#define GE 281
#define LE 282
#define GT 283
#define LT 284
#define ADD 285
#define SUB 286
#define MUL 287
#define DIV 288
#define MOD 289
#define OR 290
#define AND 291
#define BITOR 292
#define BITAND 293
#define BITXOR 294
#define NOT 295
#define COM 296
#define LSH 297
#define RSH 298
#define SET 299
#define SETADD 300
#define SETSUB 301
#define SETMUL 302
#define SETDIV 303
#define SETMOD 304
#define SETOR 305
#define SETAND 306
#define SETXOR 307
#define SETLSH 308
#define SETRSH 309
#define VOID 310
#define CHAR 311
#define SHORT 312
#define INT 313
#define LONG 314
#define FLOAT 315
#define DOUBLE 316
#define FLTVAL 318
#define DBLVAL 319
#define STRVAL 320
#define CHARVAL 321 
#define PREPROC 322

#define UNION 323


int list_type;
%}

%option noyywrap nounput yylineno
ID [a-zA-Z][a-zA-Z0-9_]*
%x COMMENT

%%
"//" {
  /****************************************
  * Matching with Single line comments in our 
  * C code
  ******************************************/
  BEGIN COMMENT;
}

<COMMENT>[\n](\r)? {
  /****************************************
  * A new line indicates end of a single 
  * line comment in C
  ****************************************/
  BEGIN 0;
}

<COMMENT>[ \t] {
  /****************************************
  * Lexer ignores the comments section
  * by Ignoring anything inside a comment
  ****************************************/
}

<COMMENT>. {
}

%{

%}

"unsigned" {
  printf("UNSIGNED\n");
  return UNSIGNED;
}

"typedef" {
  printf("TYPEDEF\n");
  return TYPEDEF;
}

"struct" {
  printf("STRUCT\n");
  return STRUCT;
}

"union" {
  printf("UNION\n");
  return UNION;
}

"const" {
  printf("CONST\n");
  return CONST;
}

"static" {
  printf("STATIC\n");
  return STATIC;
}

"extern" {
  printf("EXTERN\n");
  return EXTERN;
}

"auto" {
  printf("AUTO\n");
  return AUTO;
}

"register" {
  printf("REGISTER\n");
  return REGISTER;
}

"sizeof" {
  printf("SIZEOF\n");
  return SIZEOF;
}

%{
 
%}

"return" {
  printf("RETURN\n");
  return RETURN;
}

"do" {
  printf("DO\n");
  return DO;
}

"while" {
  printf("WHILE\n");
  return WHILE;
}

"for" {
  printf("FOR\n");
  return FOR;
}

"switch" {
  printf("SWITCH\n");
  return SWITCH;
}

"case" {
  printf("CASE\n");
  return CASE;
}

"default" {
  printf("DEFAULT\n");
  return DEFAULT;
}

"if" {
  printf("IF\n");
  return IF;
}

"else" {
  printf("ELSE\n");
  return ELSE;
}

"continue" {
  printf("CONTINUE\n");
  return CONTINUE;
}

"break" {
  printf("BREAK\n");
  return BREAK;
}

"goto" {
  printf("GOTO\n");
  return GOTO;
}

%{
 
%}

"==" {
  printf("EQ\n");
  return EQ;
}

"!=" {
  printf("NE\n");
  return NE;
}

">=" {
  printf("GE\n");
  return GE;
}

"<=" {
  printf("LE\n");
  return LE;
}

">" {
  printf("GT\n");
  return GT;
}

"<" {
  printf("LT\n");
  return LT;
}

"+" {
  printf("ADD\n");
  return ADD;
}

"-" {
  printf("SUB\n");
  return SUB;
}

"*" {
  printf("MUL\n");
  return MUL;
}

"/" {
  printf("DIV\n");
return DIV;
}

"%" {
  printf("MOD\n");
  return MOD;
}

"||" {
  printf("OR\n");
  return OR;
}

"&&" {
  printf("AND\n");
  return AND;
}

"|" {
  printf("BITOR\n");
  return BITOR;
}

"&" {
  printf("BITAND\n");
  return BITAND;
}

"^" {
  printf("BITXOR\n");
  return BITXOR;
}

"!" {
  printf("NOT\n");
  return NOT;
}

"~" {
  printf("COM\n");
  return COM;
}

"<<" {
  printf("LSH\n");
  return LSH;
}

">>" {
  printf("RSH\n");
  return RSH;
}

"=" {
  printf("SET\n");
  return SET;
}

"+=" {
  printf("SETADD\n");
  return SETADD;
}

"-=" {
  printf("SETSUB\n");
  return SETSUB;
}

"*=" {
  printf("SETMUL\n");
  return SETMUL;
}

"/=" {
  printf("SETDIV\n");
  return SETDIV;
}

"%=" {
  printf("SETMOD\n");
  return SETMOD;
}

"|=" {
  printf("SETOR\n");
  return SETOR;
}

"&=" {
  printf("SETAND\n");
  return SETAND;
}

"^=" {
  printf("SETXOR\n");
  return SETXOR;
}

"<<=" {
  printf("SETLSH\n");
  return SETLSH;
}

">>=" {
  printf("SETRSH\n");
  return SETRSH;
}

%{
 
%}

"void" {
  printf("VOID\n");
  return VOID;
}

"char" {
  printf("CHAR\n");
  return CHAR;
}

"short" {
  printf("SHORT\n");
  return SHORT;
}

"int" {
  printf("INT\n");
  return INT;
}

"long" {
  printf("LONG\n");
  return LONG;
}

"float" {
  printf("FLOAT\n");
  return FLOAT;
}

"double" {
  printf("DOUBLE\n");
  return DOUBLE;
}

%{
 
%}

[0-9]+ {
  printf("INTVAL\n");
  return INTVAL;
}

[0-9]+"."[0-9]+"f" {
  printf("FLTVAL\n");
  return FLTVAL;
}

[0-9]+"."[0-9]+ {
  printf("DBLVAL\n");
  return DBLVAL;
}

"\""[^<]*"\"" {
  printf("STRVAL\n");
  return STRVAL;
}

"'"[^<]*"'" {
  printf("CHARVAL\n");
  return CHARVAL;
}

%{
 
%}

"#" {
  printf("PREPROC\n");
  return PREPROC;
}



%{
 
%}

"(" {
  printf("(\n");
  return '(';
}

")" {
  printf(")\n");
  return ')';
}

"{" {
  printf("{\n"); 
  return '{';
}

"}" {
  printf("}\n");
  return '}';
}

"[" {
  printf("[\n");
  return '[';
}

"]" {
  printf("]\n");
  return ']';
}

"," {
  printf(",\n");
  return ',';
}

";" {
  printf(";\n");
  return ';';
}

%{
 
%}

{ID} {
printf("ID\n");
return ID;
}

[ \t\n\r]+ {
    /**************************************************************************
     * Matched some whitespace that is not inside of an HTML tag. We
     * just ignore the whitespace.
     *************************************************************************/
}

%%
int main(int argc, const char* argv[])
{
  /*Make a call to yylex() recursively. Whenever yylex() is called, it scans tokens from the 
  global input file yyin (which defaults to stdin). It continues until it either reaches an 
  end-of-file (at which point it returns the value 0) or one of its actions executes a return statement.*/

  while (yylex()) {
  }

return 0;
}
