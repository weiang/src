%option noyywrap 
%{
#include <stdio.h>
#include "header.h" 
int linenumber;
symtab * lookup();
symtab * ptr;
void     insertID();
void 	 printSymTab();

#define MAX_COMMENT_NUM 100
char *comment_table[MAX_COMMENT_NUM];
int comment_index = 0;
/* You need to define for all tokens in C--, here are some examples */
#define INT		10
#define FLOAT 		11 
#define OP_ASSIGN 	12 
#define OP_OR 		13 
#define MK_LPAREN 	14 
#define MK_RPAREN 	15 
#define ERROR 		100 

%}

letter   [A-Za-z]
digit    [0-9]
WS	 [ \t]+
F	[+\-]?(({digit}*"."{digit}+) | ({digit}+"."{digit}*)))
E	[Ee]{F}
Float_constant	{F}{E}?	
String_constant	\"(\\.|[^\\"])*\"	
Comment	[/][*]((([*])+[^/*])|([^*]))*[*][/]

OP_assign        "="
OP_or   "||"

/* Other operators appear here */ 


newline  "\n"

DL_lparen "("
DL_rparen ")"
DL_lbrace "{"
DL_rbrace "}"
DL_comma  ","
DL_semicol ";"
DL_dot  "."

/* Other separators appear here */

error    .

%%

{WS}            {}
{letter}({letter}|{digit}|_)*	{ }

{OP_assign}     /* return OP_ASSIGN; */	{ } 
{OP_or}         /* return OP_OR; */
{DL_lparen}     /* return MK_LPAREN; */
{DL_rparen}     /* return MK_RPAREN; */
{DL_lbrace}     /* return MK_LBRACE; */
{DL_rbrace}     /* return MK_RBRACE; */
{DL_comma}      {}
{DL_semicol}    {}
{newline}       linenumber += 1;
{error}         printf("ERR \n");/* return ERROR; */


%%

void comment(char *yytext)
{
	comment_table[comment_index] =(char *)malloc(strlen(yytext) + 1);
	strncpy(comment_table[comment_index], yytext, strlen(yytext));
	comment_table[comment_index][strlen(yytext)] = '\0';
	printf("%s", comment_table[comment_index]);
	comment_index ++;
}



main(int argc, char **argv)
{
 argc--; ++argv;
   if (argc > 0)
      yyin = fopen(argv[0], "r");
   else
      yyin = stdin;
   yylex();
//   printSymTab();

}

