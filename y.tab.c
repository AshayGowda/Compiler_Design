/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     DO = 260,
     WHILE = 261,
     RETURN = 262,
     VOID = 263,
     INT = 264,
     FLOAT = 265,
     CHAR = 266,
     INC_OP = 267,
     DEC_OP = 268,
     PLUS = 269,
     MINUS = 270,
     STAR = 271,
     SLASH = 272,
     LT = 273,
     LTEQ = 274,
     GT = 275,
     GTEQ = 276,
     EQ = 277,
     NEQ = 278,
     ASSIGN = 279,
     SEMI = 280,
     COMMA = 281,
     LPAREN = 282,
     RPAREN = 283,
     LSQUAR = 284,
     RSQUAR = 285,
     LBRACE = 286,
     RBRACE = 287,
     LCOMMENT = 288,
     RCOMMENT = 289,
     ID = 290,
     NUM = 291,
     FLT = 292,
     CHR = 293,
     LETTER = 294,
     DIGIT = 295,
     NONTOKEN = 296,
     ERROR = 297,
     ENDFILE = 298,
     PRINTF = 299,
     NL = 300,
     ENDL = 301,
     STR = 302,
     PREPROC = 303,
     NEW = 304,
     THEN = 305,
     LOWER_THAN_IF = 306
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define DO 260
#define WHILE 261
#define RETURN 262
#define VOID 263
#define INT 264
#define FLOAT 265
#define CHAR 266
#define INC_OP 267
#define DEC_OP 268
#define PLUS 269
#define MINUS 270
#define STAR 271
#define SLASH 272
#define LT 273
#define LTEQ 274
#define GT 275
#define GTEQ 276
#define EQ 277
#define NEQ 278
#define ASSIGN 279
#define SEMI 280
#define COMMA 281
#define LPAREN 282
#define RPAREN 283
#define LSQUAR 284
#define RSQUAR 285
#define LBRACE 286
#define RBRACE 287
#define LCOMMENT 288
#define RCOMMENT 289
#define ID 290
#define NUM 291
#define FLT 292
#define CHR 293
#define LETTER 294
#define DIGIT 295
#define NONTOKEN 296
#define ERROR 297
#define ENDFILE 298
#define PRINTF 299
#define NL 300
#define ENDL 301
#define STR 302
#define PREPROC 303
#define NEW 304
#define THEN 305
#define LOWER_THAN_IF 306




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h> 
#include "lex.yy.c"
FILE *symtab;
#define release 1
#define MAXCHILD 10
FILE *syntree;
extern void yyerror(const char *);
extern int yylex(void);
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;

int iasval, itermval, iexpval;
char casval, ctermval, cexpval;
float fasval, ftermval, fexpval;
int cflag=0, iflag=0, fflag=0;
char* tab="  ";
char indent[100]="";
char type[200];
char if_stmt_skip_label[10];
char* integer="INT";
char* floating="float";
char* none = "none";
char* assign = "=";
int expval=0;
int errors = 0;
/*Stack*/

FILE *icgout;



/*Data Structure to store quadruples*/
struct quadruple{
    char statement[30];
    char op[10];
    char arg1[20];
    char arg2[20];
    char res[20];
    int lineno;
    struct quadruple *next;
};
typedef struct quadruple quadruple;

struct quad_list{
    quadruple* head;
};
typedef struct quad_list quad_list;
quad_list* q_list1;

quadruple* create_quadruple(char* statement,char* op, char* arg1, char* arg2, char* res, int lineno) {
    quadruple* new_quadruple = (quadruple*)malloc(sizeof(quadruple));
    strcpy(new_quadruple->statement,statement);
    strcpy(new_quadruple->op,op);
    strcpy(new_quadruple->arg1,arg1);
    strcpy(new_quadruple->arg2,arg2);
    strcpy(new_quadruple->res,res);
    new_quadruple->lineno = lineno;
    
    //printf("Created quadruple record...\n");
    new_quadruple->next=NULL;
    return new_quadruple;
}
void insert_quadruple(quad_list * list, quadruple* q1) {
    quadruple * traverse = list->head;
    if(traverse==NULL) {
        list->head = q1;
    }
    else {
        while (traverse->next !=NULL) {
            traverse = traverse->next;
        }
        traverse->next = q1;
    }
}
char* get_three_add(quadruple* record) {
    char *res = (char *)malloc(sizeof(char)*50);
    if(strcmp(record->statement,"expression") == 0) {
        sprintf(res,"%s = %s %s %s",record->res,record->arg1,record->op,record->arg2);
    }
    else if(strcmp(record->statement,"assignment") == 0){
        sprintf(res,"%s = %s %s",record->res,record->op,record->arg1);   
    }
    else if(strcmp(record->statement,"conditional_goto") == 0){
        sprintf(res,"if %s %s %s goto %s",record->arg1,record->op,record->arg2,record->res);
    }
    else if(strcmp(record->statement,"goto") == 0){
        sprintf(res,"goto %s",record->res);
    }
    else if(strcmp(record->statement,"label") == 0 ){
        sprintf(res,"%s : ",record->res);
    }
    else if(strcmp(record->statement, "unary")==0){
    	sprintf(res, "%s = %s %s", record->res, record->arg1, record->arg2);
    }
    else if(strcmp(record->statement, "condition")==0){
    	sprintf(res, "%s", record->res);
    }
    else if(strcmp(record->statement, "ARR")==0){
    	sprintf(res, "ARR %s = %s", record->res, record->arg1);
    }
    return res;
}

void display_three_add(quad_list *list) {
    quadruple *traverse = list->head;
    while(traverse!=NULL) {
    	printf("%s\n", get_three_add(traverse));
        fprintf(icgout, "%s\n",get_three_add(traverse));

        traverse=traverse->next;
    }
}



int temp_count = 0;
int label_count = 0;
char * create_temp() {
    char *new_temp = (char*)malloc(sizeof(char)*10);
    sprintf(new_temp,"t%d",temp_count);
    temp_count+=1;
    //printf("Created temporary variable : %d",temp_count);
    return new_temp;
}
char * create_label() {
    char *new_label=(char*)malloc(sizeof(char)*10);
    sprintf(new_label,"L%d",label_count);
    label_count+=1;
    return new_label;
}
char * get_previous_temp() {
    //char *new_temp = (char*)malloc(sizeof(char)*10);
    //sprintf(new_temp,"t%d",temp_count-1);
    quadruple * traversal = q_list1->head;
    if(traversal==NULL) return "";
    while(traversal->next!=NULL) {
        traversal=traversal->next;
    }
    return traversal->res;
}

char * get_dtype(char * str) {
    int i=0;
    char* type = (char*)malloc(sizeof(char)*10);
    if(str[0]=='\"') {
        strcpy(type,"STRING");
        return type;
    }
    else if(str[0]=='\'') {
        strcpy(type,"CHAR");
        return type;
    }
    strcpy(type,"INT");
    while(str[i]!='\0' && str[i]>=0 && str[i]<=9) {
        i++;
    }
    if (str[i]=='\0') {
        return type;
    }
    else if (str[i]=='.') {
        strcpy(type,"FLOAT");
        i++;
        while(str[i]!='\0' && str[i]>=0 && str[i]<=9) {
            i++;
        }
        if (str[i]=='\0') {
        return type;
    }
    else {
        strcpy(type,"INVALID");
        return type;
    }
    }
    return type;
}
//end of quadruples code
struct construct {
    char start_label[10];
    char stop_label[10];
};

typedef struct construct construct;
construct current_construct;

//end
struct node{
    int nl;
    char name[100];
    char dtype[200];
    int scope;
    int value;
    float fvalue;
    char cvalue;
    char rhs[200];
    char type[100];
    struct node *next;

};
typedef struct node node;
struct list{
    node* head;
};

typedef struct list list1;
struct list* list2 = NULL;

int exists(list1* root, char name[100], int scope){
    if(root == NULL || root->head == NULL){
        return 0;
    }
    node *t2 = root->head;
    while(t2!=NULL){
        if(strcmp(t2->name, name) == 0 && t2->scope == scope){
            
            
            return 1;
        }
        t2 = t2->next;
    }
    t2 = root->head;
    while(t2!=NULL){
    	if(strcmp(t2->name, name)==0){
    		return 1;
    	}
    	t2 = t2->next;
    }
    
    return 0;

}
node* find(list1 *root, char name[200], int scope){
    if(root == NULL || root->head == NULL){
        return NULL;
    }
    node *t2 = root->head;
    while(t2!=NULL){
        if(strcmp(t2->name, name)==0 && t2->scope == scope){return t2;}
        t2 = t2->next;
    }
    t2 = root->head;
    while(t2!=NULL){
    	if(strcmp(t2->name, name)==0){
    		return t2;
    	}
    	t2 = t2->next;
    }
    return t2;

}
node* id_ex;
void insert(list1 *root, int nl, char name[100], char dtype[200], int scope, char rhs[200], char type[100]){
    int out = exists(root, name, scope);
    
    if(out == 0){
    node *temp = (node*)malloc(sizeof(node));
    temp->nl = nl;
    temp->scope = scope;
    strcpy(temp->dtype, dtype);
    strcpy(temp->rhs, rhs);
    strcpy(temp->name, name);
    strcpy(temp->type, type);
    temp->next = NULL;
    if(root->head == NULL){
        root->head = temp;
        return;
    }
    node *t2 = root->head;
    while(t2->next!=NULL){
        t2 = t2->next;
    }
    t2->next = temp;
    return;

}
else{
	errors++;
	printf("Error at line %d: Multiple declarations\n", nl);
}
}

void update(list1 *root, char name[100], int scope,  char rhs[200]){
    node *t2 = root->head;
    if(find(root, name, scope) == NULL){
        return;
    }
    while(strcmp(t2->name, name)!=0){
        t2 = t2->next;
    }
    strcpy(t2->rhs, rhs);
    
    return;
}

void print(node *head){
    // printf("1\n");
    node *temp = head;
    printf("___________________________________________________________________\n");
    fprintf(symtab, "___________________________________________________________________\n");
    printf("|Line      |Name      |Scope     |value     |id_type   |datatype  |\n");
    fprintf(symtab, "|Line      |Name      |Scope     |value     |id_type   |datatype  |\n");
    printf("-------------------------------------------------------------------\n");
    fprintf(symtab, "-------------------------------------------------------------------\n");
    while(temp!=NULL){

        printf("|%-10d|%-10s|%-10d|%-10s|%-10s|%-10s|\n", temp->nl, temp->name, temp->scope, temp->rhs, temp->type, temp->dtype);
        fprintf(symtab, "|%-10d|%-10s|%-10d|%-10s|%-10s|%-10s|\n", temp->nl, temp->name, temp->scope, temp->rhs, temp->type, temp->dtype);      	
        temp=temp->next;
    }

    printf("-------------------------------------------------------------------\n");
    fprintf(symtab, "-------------------------------------------------------------------\n");
}

void reset_scope(list1 *root, int current_scope) {
    if(root == NULL || root->head == NULL){
        return;
    }
    node *t2 = root->head;
    while (t2!=NULL) {
        if(t2->scope > current_scope) {
            t2->scope=-1;
        }
        t2=t2->next;
    }
}

struct expression_details{
    //int value;
    char type[200];
};
typedef struct expression_details exp_det;
exp_det det1;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 342 "parser.y"
{
	char chr;
	int integer;
	float ft;
	char *str;
}
/* Line 193 of yacc.c.  */
#line 546 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 559 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    16,    21,    23,    25,
      29,    33,    36,    40,    44,    46,    51,    54,    60,    62,
      66,    70,    76,    79,    83,    88,    90,    92,    94,    96,
      99,   102,   107,   112,   114,   116,   119,   123,   125,   128,
     130,   132,   134,   136,   138,   140,   142,   144,   146,   152,
     154,   157,   160,   162,   164,   166,   168,   171,   172,   173,
     182,   183,   184,   194,   197,   198,   200,   202,   204,   206,
     207,   208,   218,   221,   225,   227,   229,   233,   237,   239,
     242,   245,   247,   250,   253,   255,   259,   261,   263,   265,
     267,   269,   271,   273,   277,   281,   284,   287,   289,   291,
     295,   299,   304,   309,   313,   315,   317,   319,   321,   323,
     327,   332,   334
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    55,    -1,    54,    55,    -1,
      54,    48,    18,    35,    20,    -1,    48,    18,    35,    20,
      -1,    56,    -1,    62,    -1,    63,    60,    25,    -1,    63,
      59,    25,    -1,     1,    25,    -1,    31,    58,    32,    -1,
      36,    26,    58,    -1,    36,    -1,    35,    29,    36,    30,
      -1,    16,    35,    -1,    35,    29,    30,    24,    57,    -1,
      35,    -1,    35,    24,    86,    -1,    60,    26,    35,    -1,
      60,    26,    35,    24,    86,    -1,    27,    28,    -1,    27,
      65,    28,    -1,    63,    35,    61,    66,    -1,     9,    -1,
       8,    -1,    10,    -1,    11,    -1,     9,    35,    -1,    10,
      35,    -1,    64,    26,     9,    35,    -1,    64,    26,    10,
      35,    -1,    64,    -1,     8,    -1,    31,    32,    -1,    31,
      67,    32,    -1,    68,    -1,    67,    68,    -1,    56,    -1,
      69,    -1,    74,    -1,    66,    -1,    75,    -1,    82,    -1,
      70,    -1,    85,    -1,    71,    -1,    44,    27,    72,    28,
      25,    -1,    73,    -1,    73,    72,    -1,    73,    46,    -1,
      36,    -1,    47,    -1,    35,    -1,    25,    -1,    86,    25,
      -1,    -1,    -1,     3,    27,    86,    28,    76,    69,    77,
      78,    -1,    -1,    -1,     4,     3,    27,    86,    28,    79,
      69,    80,    78,    -1,     4,    81,    -1,    -1,    74,    -1,
      66,    -1,    82,    -1,    85,    -1,    -1,    -1,     5,    83,
      69,    84,     6,    27,    86,    28,    25,    -1,     7,    25,
      -1,     7,    86,    25,    -1,    87,    -1,    90,    -1,    35,
      24,    86,    -1,    94,    24,    86,    -1,    88,    -1,    12,
      35,    -1,    13,    35,    -1,    89,    -1,    35,    12,    -1,
      35,    13,    -1,    92,    -1,    92,    91,    92,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    93,    -1,    92,    14,    92,    -1,    92,    15,    92,
      -1,    14,    92,    -1,    15,    92,    -1,    95,    -1,    94,
      -1,    93,    16,    93,    -1,    93,    17,    93,    -1,    35,
      29,    36,    30,    -1,    35,    29,    35,    30,    -1,    27,
      86,    28,    -1,    35,    -1,    96,    -1,    36,    -1,    37,
      -1,    47,    -1,    35,    27,    28,    -1,    35,    27,    97,
      28,    -1,    86,    -1,    86,    26,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   374,   374,   377,   378,   379,   380,   384,   385,   389,
     391,   392,   395,   398,   399,   402,   403,   404,   409,   415,
     432,   439,   461,   462,   466,   470,   471,   472,   473,   477,
     478,   479,   480,   485,   486,   490,   491,   495,   496,   500,
     501,   505,   506,   507,   508,   509,   510,   514,   517,   519,
     520,   521,   524,   525,   526,   542,   543,   548,   566,   548,
     581,   599,   581,   606,   609,   613,   614,   615,   616,   620,
     627,   620,   649,   650,   654,   655,   659,   676,   702,   705,
     737,   769,   773,   802,   839,   840,   849,   850,   851,   852,
     853,   854,   858,   860,   874,   888,   889,   893,   896,   897,
     912,   929,   947,   976,   977,   991,   994,   998,  1002,  1007,
    1008,  1012,  1013
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "DO", "WHILE", "RETURN",
  "VOID", "INT", "FLOAT", "CHAR", "INC_OP", "DEC_OP", "PLUS", "MINUS",
  "STAR", "SLASH", "LT", "LTEQ", "GT", "GTEQ", "EQ", "NEQ", "ASSIGN",
  "SEMI", "COMMA", "LPAREN", "RPAREN", "LSQUAR", "RSQUAR", "LBRACE",
  "RBRACE", "LCOMMENT", "RCOMMENT", "ID", "NUM", "FLT", "CHR", "LETTER",
  "DIGIT", "NONTOKEN", "ERROR", "ENDFILE", "PRINTF", "NL", "ENDL", "STR",
  "PREPROC", "NEW", "THEN", "LOWER_THAN_IF", "$accept", "atree", "program",
  "external_declaration", "var_declaration", "array_init", "comma_list",
  "array_dec", "init_declarator_list", "declarator", "fun_declaration",
  "declaration_specifiers", "params_list", "params", "compound_stmt",
  "block_item_list", "block_item", "statement", "input_output", "printf",
  "print_out", "op", "expression_stmt", "if_stmt", "@1", "@2", "else_if",
  "@3", "@4", "else_body", "do_while_stmt", "@5", "@6", "return_stmt",
  "expression", "assignment_expression", "unary_expression",
  "postfix_expression", "simple_expression", "relop",
  "additive_expression", "term", "arrayindex", "factor", "call", "args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    55,    56,
      56,    56,    57,    58,    58,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    62,    63,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    70,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    76,    77,    75,
      79,    80,    78,    78,    78,    81,    81,    81,    81,    83,
      84,    82,    85,    85,    86,    86,    87,    87,    87,    88,
      88,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    96,
      96,    97,    97
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     4,     1,     1,     3,
       3,     2,     3,     3,     1,     4,     2,     5,     1,     3,
       3,     5,     2,     3,     4,     1,     1,     1,     1,     2,
       2,     4,     4,     1,     1,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       2,     2,     1,     1,     1,     1,     2,     0,     0,     8,
       0,     0,     9,     2,     0,     1,     1,     1,     1,     0,
       0,     9,     2,     3,     1,     1,     3,     3,     1,     2,
       2,     1,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     2,     1,     1,     3,
       3,     4,     4,     3,     1,     1,     1,     1,     1,     3,
       4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    26,    25,    27,    28,     0,     0,     0,     3,
       7,     8,     0,    11,     0,     1,     0,     4,     0,    18,
       0,     0,     0,     0,    16,     0,     0,     0,     0,    10,
       9,     0,     6,     0,     0,     0,     0,     0,     0,   104,
     106,   107,   108,    19,    74,    78,    81,    75,    84,    92,
      98,    97,   105,    34,     0,     0,    22,    33,     0,     0,
       0,     0,    24,    20,     5,    79,    80,   104,    95,    98,
      96,     0,    82,    83,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,    29,
      30,     0,    23,     0,    15,     0,    69,     0,    55,    35,
       0,    39,     0,    42,     0,    37,    40,    45,    47,    41,
      43,    44,    46,     0,     0,   103,    76,   109,   111,     0,
       0,     0,    93,    94,    85,    99,   100,    77,     0,     0,
       0,    17,     0,     0,    72,     0,     0,    18,    36,    38,
      56,    21,     0,   110,   102,   101,    31,    32,    14,     0,
       0,    70,    73,    54,    52,    53,     0,    49,   112,     0,
      12,    57,     0,     0,    51,    50,    13,     0,     0,    48,
      58,     0,    64,     0,     0,    59,     0,     0,    66,    65,
      63,    67,    68,    71,     0,     0,    60,     0,    61,    64,
      62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,   131,   149,    20,    21,    28,
      11,    12,    57,    58,   103,   104,   105,   106,   107,   108,
     156,   157,   109,   110,   167,   172,   175,   187,   189,   180,
     111,   133,   162,   112,   113,    44,    45,    46,    47,    85,
      48,    49,    50,    51,    52,   119
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
      13,   -20,  -132,  -132,  -132,  -132,    -2,    25,     9,  -132,
    -132,  -132,    -5,  -132,    -3,  -132,    72,  -132,     8,    35,
      45,    57,    80,    84,  -132,   232,    18,    -1,    61,  -132,
    -132,    94,  -132,   114,   100,   101,   236,   236,   232,   253,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    19,    68,
      91,  -132,  -132,  -132,   102,   104,  -132,   117,   123,   129,
     125,    66,  -132,   134,  -132,  -132,  -132,    39,  -132,  -132,
    -132,   137,  -132,  -132,   232,   202,    69,   236,   236,  -132,
    -132,  -132,  -132,  -132,  -132,   236,    59,    59,   232,  -132,
    -132,    99,  -132,   135,  -132,   140,  -132,   206,  -132,  -132,
     141,  -132,    -4,  -132,   113,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,   144,   232,  -132,  -132,  -132,   145,   142,
     143,   147,  -132,  -132,    97,  -132,  -132,  -132,   152,   157,
     136,  -132,   232,   149,  -132,   150,    52,    36,  -132,  -132,
    -132,  -132,   232,  -132,  -132,  -132,  -132,  -132,   156,   146,
     166,  -132,  -132,  -132,  -132,  -132,   167,    95,  -132,   136,
    -132,  -132,   191,   173,  -132,  -132,  -132,   149,   172,  -132,
    -132,   232,   196,   174,   176,  -132,   179,   178,  -132,  -132,
    -132,  -132,  -132,  -132,   232,   180,  -132,   149,  -132,   196,
    -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,   198,   -53,  -132,    50,  -132,  -132,  -132,
    -132,   -46,  -132,  -132,   -27,  -132,   106,  -131,  -132,  -132,
      65,  -132,    51,  -132,  -132,  -132,    37,  -132,  -132,  -132,
      53,  -132,  -132,    54,   -25,  -132,  -132,  -132,  -132,  -132,
     -30,    46,   -33,  -132,  -132,    82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      43,    62,   151,    69,    69,    13,    68,    70,   101,    -2,
       1,    18,    18,    71,     1,   102,    14,     2,     3,     4,
       5,     2,     3,     4,     5,    15,    53,    54,    55,    59,
      19,   137,    22,    77,    78,    60,   170,    79,    80,    81,
      82,    83,    84,    24,    69,    69,    56,   122,   123,   116,
     118,   101,    69,    69,    69,   124,   188,    16,   102,    25,
      25,     6,    26,   127,    27,    27,    75,     1,    76,    95,
      29,    96,   135,    97,     2,     3,     4,     5,    34,    35,
      36,    37,    30,    31,    86,    87,    38,   153,   154,   141,
      23,    98,    61,    38,    67,    40,    41,    61,    99,   155,
      32,    39,    40,    41,   120,   121,    42,   150,   128,   129,
     100,    77,    78,    42,     1,    88,    95,   118,    96,    33,
      97,     2,     3,     4,     5,    34,    35,    36,    37,    63,
     153,   154,   125,   126,    64,    65,    66,    89,    98,    90,
      38,   164,   155,    91,    61,   138,   173,   178,    39,    40,
      41,    92,    95,    93,    96,    94,    97,   100,   114,   185,
      42,    34,    35,    36,    37,   115,   130,   132,   136,   140,
     143,   142,   148,   144,    98,   152,    38,   145,   160,   177,
      61,    96,   159,    97,    39,    40,    41,   146,    34,    35,
      36,    37,   147,   100,   161,   163,    42,   168,   169,   171,
     174,    98,   176,    38,   183,   184,    17,    61,   186,   166,
     139,    39,    40,    41,    34,    35,    36,    37,    34,    35,
      36,    37,   165,    42,   158,   179,   190,   181,   182,    38,
     117,   134,     0,    38,     0,     0,     0,    39,    40,    41,
       0,    39,    40,    41,    34,    35,    36,    37,     0,    42,
      36,    37,     0,    42,     0,     0,     0,     0,     0,    38,
       0,     0,     0,    38,     0,    72,    73,    39,    40,    41,
       0,    67,    40,    41,     0,     0,     0,    74,     0,    42,
      75,     0,    76,    42
};

static const yytype_int16 yycheck[] =
{
      25,    28,   133,    36,    37,    25,    36,    37,    61,     0,
       1,    16,    16,    38,     1,    61,    18,     8,     9,    10,
      11,     8,     9,    10,    11,     0,     8,     9,    10,    30,
      35,    35,    35,    14,    15,    36,   167,    18,    19,    20,
      21,    22,    23,    35,    77,    78,    28,    77,    78,    74,
      75,   104,    85,    86,    87,    85,   187,    48,   104,    24,
      24,    48,    27,    88,    29,    29,    27,     1,    29,     3,
      25,     5,    97,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    25,    26,    16,    17,    27,    35,    36,   114,
      18,    25,    31,    27,    35,    36,    37,    31,    32,    47,
      20,    35,    36,    37,    35,    36,    47,   132,     9,    10,
      44,    14,    15,    47,     1,    24,     3,   142,     5,    35,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    35,
      35,    36,    86,    87,    20,    35,    35,    35,    25,    35,
      27,    46,    47,    26,    31,    32,   171,   174,    35,    36,
      37,    28,     3,    24,     5,    30,     7,    44,    24,   184,
      47,    12,    13,    14,    15,    28,    31,    27,    27,    25,
      28,    26,    36,    30,    25,    25,    27,    30,    32,     3,
      31,     5,    26,     7,    35,    36,    37,    35,    12,    13,
      14,    15,    35,    44,    28,    28,    47,     6,    25,    27,
       4,    25,    28,    27,    25,    27,     8,    31,    28,   159,
     104,    35,    36,    37,    12,    13,    14,    15,    12,    13,
      14,    15,   157,    47,   142,   174,   189,   174,   174,    27,
      28,    25,    -1,    27,    -1,    -1,    -1,    35,    36,    37,
      -1,    35,    36,    37,    12,    13,    14,    15,    -1,    47,
      14,    15,    -1,    47,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    27,    -1,    12,    13,    35,    36,    37,
      -1,    35,    36,    37,    -1,    -1,    -1,    24,    -1,    47,
      27,    -1,    29,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     8,     9,    10,    11,    48,    53,    54,    55,
      56,    62,    63,    25,    18,     0,    48,    55,    16,    35,
      59,    60,    35,    18,    35,    24,    27,    29,    61,    25,
      25,    26,    20,    35,    12,    13,    14,    15,    27,    35,
      36,    37,    47,    86,    87,    88,    89,    90,    92,    93,
      94,    95,    96,     8,     9,    10,    28,    64,    65,    30,
      36,    31,    66,    35,    20,    35,    35,    35,    92,    94,
      92,    86,    12,    13,    24,    27,    29,    14,    15,    18,
      19,    20,    21,    22,    23,    91,    16,    17,    24,    35,
      35,    26,    28,    24,    30,     3,     5,     7,    25,    32,
      44,    56,    63,    66,    67,    68,    69,    70,    71,    74,
      75,    82,    85,    86,    24,    28,    86,    28,    86,    97,
      35,    36,    92,    92,    92,    93,    93,    86,     9,    10,
      31,    57,    27,    83,    25,    86,    27,    35,    32,    68,
      25,    86,    26,    28,    30,    30,    35,    35,    36,    58,
      86,    69,    25,    35,    36,    47,    72,    73,    97,    26,
      32,    28,    84,    28,    46,    72,    58,    76,     6,    25,
      69,    27,    77,    86,     4,    78,    28,     3,    66,    74,
      81,    82,    85,    25,    27,    86,    28,    79,    69,    80,
      78
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 374 "parser.y"
    {display_three_add(q_list1);}
    break;

  case 3:
#line 377 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 4:
#line 378 "parser.y"
    {}
    break;

  case 5:
#line 379 "parser.y"
    {}
    break;

  case 6:
#line 380 "parser.y"
    {}
    break;

  case 7:
#line 384 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); }
    break;

  case 8:
#line 385 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 9:
#line 390 "parser.y"
    {}
    break;

  case 10:
#line 391 "parser.y"
    {}
    break;

  case 11:
#line 392 "parser.y"
    {yyerrok;}
    break;

  case 12:
#line 395 "parser.y"
    {(yyval.str)=(yyvsp[(2) - (3)].str);}
    break;

  case 13:
#line 398 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (3)].str);strcat((yyval.str),",");strcat((yyval.str),(yyvsp[(3) - (3)].str));}
    break;

  case 14:
#line 399 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 15:
#line 402 "parser.y"
    {insert(list2, yylineno, (yyvsp[(1) - (4)].str), type, scope, " ", "ARRAY");}
    break;

  case 16:
#line 403 "parser.y"
    {insert(list2, yylineno, (yyvsp[(2) - (2)].str), type, scope, " ", "PTR");}
    break;

  case 17:
#line 404 "parser.y"
    { insert(list2, yylineno, (yyvsp[(1) - (5)].str), "int" , scope, (yyvsp[(5) - (5)].str), "ARRAY");
    									   quadruple * new_record = create_quadruple("ARR","",(yyvsp[(5) - (5)].str),"",(yyvsp[(1) - (5)].str), yylineno);
                            			   insert_quadruple(q_list1,new_record);  }
    break;

  case 18:
#line 409 "parser.y"
    {	id_ex = find(list2, (yyvsp[(1) - (1)].str), scope+1);
    		if(id_ex !=NULL){
    			printf("Error on line %d, multiple definitions\n", yylineno);
    		}
    		else
    		insert(list2, yylineno, (yyvsp[(1) - (1)].str), type, scope, " ", "IDENT");}
    break;

  case 19:
#line 415 "parser.y"
    {
    						id_ex = find(list2, (yyvsp[(1) - (3)].str), scope+1);
    						if(id_ex !=NULL){
    							printf("Error on line %d, multiple definitions\n", yylineno);
    						}
    						else{
                            char arg1[10];
                            sprintf(arg1,"%s",(yyvsp[(3) - (3)].str));
    						quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(1) - (3)].str), yylineno);
                            insert_quadruple(q_list1,new_record); 
                            insert(list2, yylineno, (yyvsp[(1) - (3)].str), type, scope, " ", "IDENT");
                            update(list2, (yyvsp[(1) - (3)].str), scope, (yyvsp[(3) - (3)].str));
                            iflag = 0;
                            fflag = 0;
                            cflag = 0; 
                            }
                        }
    break;

  case 20:
#line 432 "parser.y"
    { id_ex = find(list2, (yyvsp[(3) - (3)].str), scope+1);
    								  if(id_ex !=NULL){
    									printf("Error on line %d, multiple definitions\n", yylineno);
    								}				
    								else
    									insert(list2, yylineno, (yyvsp[(3) - (3)].str), type, scope, " ", "IDENT"); 
    }
    break;

  case 21:
#line 439 "parser.y"
    {
    						id_ex = find(list2, (yyvsp[(3) - (5)].str), scope+1);
    					    if(id_ex !=NULL){
    							printf("Error on line %d, multiple definitions\n", yylineno);
    						}
    						else{				
                            char arg1[10];
                            sprintf(arg1,"%s",(yyvsp[(5) - (5)].str));
    						quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(3) - (5)].str), yylineno);
                            insert_quadruple(q_list1,new_record); 
                            insert(list2, yylineno, (yyvsp[(3) - (5)].str), type, scope, " ", "IDENT");
                            update(list2, (yyvsp[(3) - (5)].str), scope, (yyvsp[(5) - (5)].str));
                            iflag = 0;
                            fflag = 0;
                            cflag = 0; 
                            }
                        }
    break;

  case 22:
#line 461 "parser.y"
    {}
    break;

  case 23:
#line 462 "parser.y"
    {}
    break;

  case 24:
#line 466 "parser.y"
    {insert(list2, yylineno, (yyvsp[(2) - (4)].str), type, scope, " ", "FUNCT");}
    break;

  case 25:
#line 470 "parser.y"
    {(yyval.str)=integer; strcpy(type, "int");}
    break;

  case 26:
#line 471 "parser.y"
    {(yyval.str)="VOID"; strcpy(type, "void");}
    break;

  case 27:
#line 472 "parser.y"
    {(yyval.str)="float"; strcpy(type, "float");}
    break;

  case 28:
#line 473 "parser.y"
    {(yyval.str)="char"; strcpy(type, "char");}
    break;

  case 29:
#line 477 "parser.y"
    {}
    break;

  case 30:
#line 478 "parser.y"
    {}
    break;

  case 31:
#line 479 "parser.y"
    {}
    break;

  case 32:
#line 480 "parser.y"
    {}
    break;

  case 33:
#line 485 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 34:
#line 486 "parser.y"
    {}
    break;

  case 35:
#line 490 "parser.y"
    {(yyval.str) = "$";}
    break;

  case 36:
#line 491 "parser.y"
    {(yyval.str) = (yyvsp[(2) - (3)].str); reset_scope(list2,scope);}
    break;

  case 37:
#line 495 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 38:
#line 496 "parser.y"
    {(yyval.str) = (yyvsp[(2) - (2)].str);}
    break;

  case 39:
#line 500 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); }
    break;

  case 40:
#line 501 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 41:
#line 505 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 42:
#line 506 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 43:
#line 507 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 44:
#line 508 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 45:
#line 509 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 46:
#line 510 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 47:
#line 514 "parser.y"
    {}
    break;

  case 49:
#line 519 "parser.y"
    {if(errors==0) printf("%s", (yyvsp[(1) - (1)].str));}
    break;

  case 50:
#line 520 "parser.y"
    {if(errors==0) printf("%s", (yyvsp[(1) - (2)].str));}
    break;

  case 51:
#line 521 "parser.y"
    {if(errors==0) printf("%s\n", (yyvsp[(1) - (2)].str));}
    break;

  case 52:
#line 524 "parser.y"
    {(yyval.str) = yylval.str;}
    break;

  case 53:
#line 525 "parser.y"
    {(yyval.str) = yylval.str;}
    break;

  case 54:
#line 526 "parser.y"
    {
		id_ex = find(list2, (yyvsp[(1) - (1)].str), scope);
		if(id_ex == NULL){
			printf("Error in Line %d : Usage before Declaration\n", yylineno);
			errors++;
		}
		else{
			if(strcmp(id_ex->dtype, "int") == 0) (yyval.integer) = id_ex->value;
			if(strcmp(id_ex->dtype, "float") == 0) (yyval.ft) = id_ex->fvalue;
			if(strcmp(id_ex->dtype, "char") == 0) (yyval.chr) = id_ex->cvalue;

		}

	}
    break;

  case 55:
#line 542 "parser.y"
    {}
    break;

  case 56:
#line 543 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (2)].str);}
    break;

  case 57:
#line 548 "parser.y"
    {
    	quadruple* new_record;
    	
        //Insert Condition
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10],true_label[10],false_label[10];
        sprintf(statement_type,"conditional_goto");
        strcpy(arg1,(yyvsp[(3) - (4)].str));
        
        strcpy(true_label,create_label());
        new_record = create_quadruple(statement_type,arg1,"","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        sprintf(statement_type,"goto");
        strcpy(false_label,create_label());
        new_record = create_quadruple(statement_type,"","","",false_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        (yyval.str)=false_label;
    }
    break;

  case 58:
#line 566 "parser.y"
    {
        quadruple* new_record;
        strcpy(if_stmt_skip_label,create_label());
        new_record = create_quadruple("goto","","","",if_stmt_skip_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",(yyvsp[(5) - (6)].str), yylineno);
        insert_quadruple(q_list1,new_record);   
    }
    break;

  case 59:
#line 573 "parser.y"
    {
        quadruple* new_record;
        new_record = create_quadruple("label","","","",if_stmt_skip_label, yylineno);
        insert_quadruple(q_list1,new_record);
    }
    break;

  case 60:
#line 581 "parser.y"
    {
        
        quadruple* new_record;
        //Insert Condition
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10],true_label[10],false_label[10];
        sprintf(statement_type,"conditional_goto");
        strcpy(arg1,(yyvsp[(4) - (5)].str));
        strcpy(true_label,create_label());

        new_record = create_quadruple(statement_type,arg1,"","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        sprintf(statement_type,"goto");
        strcpy(false_label,create_label());
        new_record = create_quadruple(statement_type,"","","",false_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",true_label, yylineno);
        insert_quadruple(q_list1,new_record);
        (yyval.str)=false_label;
    }
    break;

  case 61:
#line 599 "parser.y"
    {
        quadruple* new_record;
        new_record = create_quadruple("goto","","","",if_stmt_skip_label, yylineno); 
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("label","","","",(yyvsp[(6) - (7)].str), yylineno);
        insert_quadruple(q_list1,new_record);   
    }
    break;

  case 62:
#line 605 "parser.y"
    {}
    break;

  case 63:
#line 606 "parser.y"
    {
        //printf("else\n");
    }
    break;

  case 64:
#line 609 "parser.y"
    {}
    break;

  case 65:
#line 613 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 66:
#line 614 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 67:
#line 615 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 68:
#line 616 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 69:
#line 620 "parser.y"
    {
        quadruple* new_record;
        char do_while_label[10];
        strcpy(do_while_label,create_label());
        new_record = create_quadruple("label","","","",do_while_label, yylineno);
        insert_quadruple(q_list1,new_record);
        strcpy(current_construct.start_label,do_while_label);
        (yyval.str)=do_while_label;}
    break;

  case 70:
#line 627 "parser.y"
    {
        strcpy(current_construct.start_label,"");
        strcpy(current_construct.stop_label,"");
    }
    break;

  case 71:
#line 630 "parser.y"
    {
        quadruple* new_record;
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10],true_label[10],false_label[10];
        sprintf(statement_type,"conditional_goto");
        strcpy(arg1,(yyvsp[(7) - (9)].str));
        strcpy(false_label,create_label());
        new_record = create_quadruple(statement_type,arg1,"","",(yyvsp[(2) - (9)].str), yylineno);
        insert_quadruple(q_list1,new_record);
        new_record = create_quadruple("goto","","","",false_label, yylineno);
        insert_quadruple(q_list1,new_record);
        strcpy(current_construct.start_label,"");
        strcpy(current_construct.stop_label,"");
        new_record = create_quadruple("label","","","",false_label, yylineno);
        insert_quadruple(q_list1,new_record);
        (yyval.str)=false_label;
    }
    break;

  case 72:
#line 649 "parser.y"
    {}
    break;

  case 73:
#line 650 "parser.y"
    {}
    break;

  case 74:
#line 654 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 75:
#line 655 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str); }
    break;

  case 76:
#line 659 "parser.y"
    {
                            char arg1[10],previous_temp[10];
                            strcpy(previous_temp,get_previous_temp()); 
                            sprintf(arg1,"%s",(yyvsp[(3) - (3)].str));
    						quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(1) - (3)].str), yylineno);
                            insert_quadruple(q_list1,new_record); 
                            int ex = exists(list2,(yyvsp[(1) - (3)].str), scope); 
                            if(ex == 0) {printf("Error in Line %d : Assignment before Declaration\n", yylineno); errors++;}
                            id_ex = find(list2, (yyvsp[(1) - (3)].str), scope);
                            update(list2, (yyvsp[(1) - (3)].str), scope, (yyvsp[(3) - (3)].str));
                            iflag = 0;
                            cflag = 0;
                            fflag = 0;
                            

                        }
    break;

  case 77:
#line 676 "parser.y"
    {
    								char arg1[10], previous_temp[10];
    								strcpy(previous_temp,get_previous_temp()); 
                            		sprintf(arg1,"%s",(yyvsp[(3) - (3)].str));
    								quadruple * new_record = create_quadruple("assignment","",arg1,"",(yyvsp[(1) - (3)].str), yylineno);
                            		insert_quadruple(q_list1,new_record); 
                            		char id[200];
                            		strcpy(id, "");
                            		int tempcount = 0;
                            		char lhs[200];
                            		strcpy(lhs, (yyvsp[(1) - (3)].str));
                            		while(lhs[tempcount]!='['){
                            			id[tempcount] = lhs[tempcount];
                            			tempcount++;
                            			
                            		}
                            		id[tempcount] = '\0';
                            		int ex = exists(list2,id, scope); 
                            		if(ex == 0) {printf("Error in Line %d : Assignment before Declaration\n", yylineno); errors++;}
                            		id_ex = find(list2, id, scope);
                            		update(list2, id, scope, (yyvsp[(3) - (3)].str));
                            		iflag = 0;
                            		cflag = 0;
                            		fflag = 0;

    					}
    break;

  case 78:
#line 702 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 79:
#line 705 "parser.y"
    { 
                 id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;
                    }
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{
                    	quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"+",(yyvsp[(2) - (2)].str),"1",(yyvsp[(2) - (2)].str), yylineno); 
        				insert_quadruple(q_list1,new_record);
        				//char te[20];
        				//strcpy(te, "++");
        				//strcat(te, $2);
        				//insert(list2, yylineno, temp,"TEMP", scope, te, "TEMP");
                        char increement[20];
                        strcpy(increement,id_ex->name);
                        strcat(increement,"+1");
        				update(list2, id_ex->name,scope,increement);
                        (yyval.str) = id_ex->rhs;
                        
                    }
                    }
                }
    break;

  case 80:
#line 737 "parser.y"
    {
                 id_ex = find(list2, (yyvsp[(2) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;}
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{
                    	quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"-",(yyvsp[(2) - (2)].str),"1",(yyvsp[(2) - (2)].str), yylineno); 
        				insert_quadruple(q_list1,new_record);
        				char te[20];
        				strcpy(te, "--");
        				strcat(te, (yyvsp[(2) - (2)].str));
        				
        				//insert(list2, yylineno, temp,"TEMP", scope, te, "TEMP");
                        char decreement[20];
                        strcpy(decreement,id_ex->name);
                        strcat(decreement,"+1");
        				update(list2, id_ex->name,scope,decreement);
                        (yyval.str) = id_ex->rhs;                        
                    }
                    }

                }
    break;

  case 81:
#line 769 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 82:
#line 773 "parser.y"
    {
                 id_ex = find(list2, (yyvsp[(1) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;
                    }
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{
                        quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"+",(yyvsp[(1) - (2)].str),"1",(yyvsp[(1) - (2)].str), yylineno); 
        				insert_quadruple(q_list1,new_record);
        				strcat((yyvsp[(1) - (2)].str), "++");
        				char increement[20];
                        strcpy(increement,id_ex->name);
                        strcat(increement,"+1");
        				//insert(list2, yylineno, temp,"TEMP", scope, $1, "TEMP");
                        (yyval.str) = id_ex->rhs;
        				update(list2, id_ex->name,scope,increement);
                    }
                    }
                }
    break;

  case 83:
#line 802 "parser.y"
    {
                 id_ex = find(list2, (yyvsp[(1) - (2)].str), scope); 
                 if(id_ex==NULL){
                    printf("Error on Lineno %d : Increment operator cannot be applied to an identifier that's not declared\n", yylineno);
                    errors++;

                    }
                else {
                    if(strcmp(id_ex->dtype, "int")!=0){
                        printf("Error on Line %d : Type Mismatch\n", yylineno);
                        errors++;
                        }
                    else{

                    	quadruple* new_record;
                    	char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
                    	sprintf(statement_type,"expression");
        
       					//strcpy(temp,create_temp());
        				new_record = create_quadruple(statement_type,"-",(yyvsp[(1) - (2)].str),"1",(yyvsp[(1) - (2)].str), yylineno);  
        				insert_quadruple(q_list1,new_record);
        				strcat((yyvsp[(1) - (2)].str), "--");
        				char decreement[20];
                        strcpy(decreement,id_ex->name);
                        strcat(decreement,"+1");
        				//insert(list2, yylineno, temp,"TEMP", scope, $1, "TEMP");
        				(yyval.str) = id_ex->rhs;
        				update(list2, id_ex->name, scope,decreement);
                    }
                        
                    }
                    }
    break;

  case 84:
#line 839 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 85:
#line 840 "parser.y"
    {
    			
				strcat((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
				strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
				(yyval.str) = (yyvsp[(1) - (3)].str);                        
    		}
    break;

  case 86:
#line 849 "parser.y"
    {(yyval.str) = "<";}
    break;

  case 87:
#line 850 "parser.y"
    {(yyval.str) = "<=";}
    break;

  case 88:
#line 851 "parser.y"
    {(yyval.str) = ">";}
    break;

  case 89:
#line 852 "parser.y"
    {(yyval.str) = ">=";}
    break;

  case 90:
#line 853 "parser.y"
    {(yyval.str) = "==";}
    break;

  case 91:
#line 854 "parser.y"
    {(yyval.str) = "!=";}
    break;

  case 92:
#line 858 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);
        }
    break;

  case 93:
#line 860 "parser.y"
    {        
        quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"+",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        strcat((yyvsp[(1) - (3)].str), "+");
        strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
        (yyval.str) = temp;
    }
    break;

  case 94:
#line 874 "parser.y"
    {
    	quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"-",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        strcat((yyvsp[(1) - (3)].str), "-");
        strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
        (yyval.str) = temp;
    	}
    break;

  case 95:
#line 888 "parser.y"
    {(yyval.str) = (yyvsp[(2) - (2)].str);}
    break;

  case 96:
#line 889 "parser.y"
    {char temp[20];strcpy(temp,"-");strcat(temp,(yyvsp[(2) - (2)].str));(yyval.str) = temp;}
    break;

  case 97:
#line 893 "parser.y"
    {
              (yyval.str) = (yyvsp[(1) - (1)].str);
            }
    break;

  case 98:
#line 896 "parser.y"
    {(yyval.str) = (yyvsp[(1) - (1)].str);}
    break;

  case 99:
#line 897 "parser.y"
    {
    	quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"*",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        
    	strcat((yyvsp[(1) - (3)].str), "*");
    	strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    	insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
    	(yyval.str) = temp;
		}
    break;

  case 100:
#line 912 "parser.y"
    {
    	quadruple* new_record;
        
        char statement_type[20],arg1[10],arg2[10],arg3[10],temp[10];
        sprintf(statement_type,"expression");
        
        strcpy(temp,create_temp());
        new_record = create_quadruple(statement_type,"/",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),temp, yylineno); 
        insert_quadruple(q_list1,new_record);
        
    	strcat((yyvsp[(1) - (3)].str), "/");
    	strcat((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    	insert(list2, yylineno, temp,"TEMP", scope, (yyvsp[(1) - (3)].str), "TEMP");
    	(yyval.str) = temp;
		}
    break;

  case 101:
#line 929 "parser.y"
    {
					char lhs[200];
					strcpy(lhs, "");
					strcat(lhs, (yyvsp[(1) - (4)].str));
					strcat(lhs, "[");
					strcat(lhs, (yyvsp[(3) - (4)].str));
					strcat(lhs, "]");
					id_ex = find(list2, (yyvsp[(1) - (4)].str), scope);
					if(id_ex == NULL){
						printf("Error on %d, Assignment RHS not declared\n", yylineno);
            			errors++;
            			(yyval.str) = "$";
					}
					else{
						(yyval.str) = lhs;
						strcpy(det1.type, id_ex->dtype);
					}
					}
    break;

  case 102:
#line 947 "parser.y"
    {
					char lhs[200];
					strcpy(lhs, "");
					strcat(lhs, (yyvsp[(1) - (4)].str));
					strcat(lhs, "[");
					strcat(lhs, (yyvsp[(3) - (4)].str));
					strcat(lhs, "]");
					id_ex = find(list2, (yyvsp[(3) - (4)].str), scope);
					if(id_ex == NULL){
						printf("Error on %d, Usage before declaration\n", yylineno);
						errors++;
						(yyval.str) = "$";
					}
					else{
					id_ex = find(list2, (yyvsp[(1) - (4)].str), scope);
					if(id_ex == NULL){
						printf("Error on %d, Assignment RHS not declared\n", yylineno);
            			errors++;
            			(yyval.str) = "$";
					}

					else{
						(yyval.str) = lhs;
						strcpy(det1.type, id_ex->dtype);
					}
					}
					}
    break;

  case 103:
#line 976 "parser.y"
    {(yyval.str)=(yyvsp[(2) - (3)].str); }
    break;

  case 104:
#line 977 "parser.y"
    {
    	  if(yylineno == 1){
    	  	(yyval.str) = (yyvsp[(1) - (1)].str);
    	  }	
    	  else{
          id_ex = find(list2, (yyvsp[(1) - (1)].str), scope);
          if(id_ex == NULL){
            printf("Error on %d, Assignment RHS not declared\n", yylineno);
            errors++;
            (yyval.str) = "$";}
          else{
          	(yyval.str) = (yyvsp[(1) - (1)].str);
            strcpy(det1.type,id_ex->dtype);            
          }}}
    break;

  case 105:
#line 991 "parser.y"
    {
        (yyval.str)=(yyvsp[(1) - (1)].str);
        }
    break;

  case 106:
#line 994 "parser.y"
    { 
           (yyval.str) = yylval.str;
           strcpy(det1.type,"int");
           }
    break;

  case 107:
#line 998 "parser.y"
    {
        (yyval.str) = yylval.str;
        strcpy(det1.type,"float");
    	}
    break;

  case 108:
#line 1002 "parser.y"
    {(yyval.str) = yylval.str;strcpy(det1.type,"string");}
    break;

  case 109:
#line 1007 "parser.y"
    {}
    break;

  case 110:
#line 1008 "parser.y"
    {}
    break;

  case 111:
#line 1012 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 112:
#line 1013 "parser.y"
    {}
    break;


/* Line 1267 of yacc.c.  */
#line 2935 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1016 "parser.y"

#include <stdio.h>
int main(argc, argv)
int argc;
char** argv;
{

FILE *fp = fopen("tokens.txt", "w");
icgout = fopen("icg.txt", "w");
symtab = fopen("symtab.txt", "w");
fclose(fp);
if (argc > 1)
{
    FILE *file;
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "failed open");
        exit(1);
    }
    yyin=file;
    //printf("success open %s\n", argv[1]);
}
else
{
    printf("no input file\n");
    exit(1);
}
list2 = (struct list*)malloc(sizeof(struct list));
list2->head = NULL;
q_list1 = (quad_list*)malloc(sizeof(quad_list));
q_list1->head = NULL;
yyparse();  
print(list2->head);
if(errors>0){
	printf("%d Errors Found\n", errors);
} else {
    //display_three_add(q_list1);
}
fclose(icgout);
fclose(symtab);
return 0; 
} 

void yyerror(const char *s)
{
	fflush(stdout);
	errors++;
	fprintf(stderr, "Error: %s on line number %d\n", s, yylineno);
}




