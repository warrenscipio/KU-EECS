#define ID 257
#define INTVAL 258
#define FLTVAL 259
#define DBLVAL 260
#define STRVAL 261
#define CHARVAL 262
#define VOID 263
#define CHAR 264
#define SHORT 265
#define INT 266
#define LONG 267
#define FLOAT 268
#define DOUBLE 269
#define RETURN 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define SET 274
#define EQ 275
#define NE 276
#define GE 277
#define LE 278
#define GT 279
#define LT 280
#define ADD 281
#define SUB 282
#define MUL 283
#define DIV 284
#define MOD 285
#define OR 286
#define AND 287
#define BITOR 288
#define BITAND 289
#define BITXOR 290
#define LSH 291
#define RSH 292
#define UNSIGNED 293
#define TYPEDEF 294
#define STRUCT 295
#define UNION 296
#define CONST 297
#define STATIC 298
#define EXTERN 299
#define AUTO 300
#define REGISTER 301
#define SIZEOF 302
#define DO 303
#define FOR 304
#define SWITCH 305
#define CASE 306
#define DEFAULT 307
#define CONTINUE 308
#define BREAK 309
#define GOTO 310
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    char* id;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
