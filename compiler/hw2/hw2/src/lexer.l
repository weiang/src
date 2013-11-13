%option noyywrap
%{
#include <stdio.h>
#include <string.h>
#include "header.h"

#define MAX_COMMENT_LENGTH	100
#define MAX_ID_NUM			1000

#define CONST_INT	1
#define CONST_FLOAT	2
#define CONST_STRING 7
#define IDENTIFIER	3
#define OR			4
#define AND			5
#define NOT			6
#define LESS_EQU	10
#define MORE_EQU	11
#define N_EQU		12
#define EQU			13
/* Key word */
#define RETURN		14
#define TYPEDEF		15
#define IF			16
#define ELSE		17
#define INT			18
#define FLOAT		19
#define FOR			20
#define STRUCT		21
#define UNION		22
#define VOID		23
#define WHILE		24

char *identifiers[MAX_COMMENT_LENGTH];
int id_reference[MAX_COMMENT_LENGTH];
int id_num = 0;

int linenumber = 0;
void printSymTab();
void id(char *);
void comment(char *);
char *comment_table[MAX_COMMENT_LENGTH];
int comment_index = 0;

%}

letter	[A-Za-z]
digit	[0-9]
split	[ \t\n]
e		[Ee]{digit}+
ws		[ \t]
newline	[\n]

	// /\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/		{ comment(yytext);}
	// Comment	[/][*]((([*])+[^/*])|([^*]))*[*][/]
Comment ([/][*]([^*]|[\r\n]|([*]+([^*/]|[\r\n])))*[*]+[/])|[/][/].*

%%

{ws}*		{}
{newline}	{}
"return"	{ return RETURN;	}
"typedef"	{ return TYPEDEF;	}
"if"		{ return IF;		}
"else"		{ return ELSE;		}
"int"		{ return INT;		}
"float"		{ return FLOAT;		}
"for"		{ return FOR;		}
"struct"	{ return STRUCT;	}
"union"		{ return UNION;		}
"void"		{ return VOID;		}
"while"		{ return WHILE;		}

[+-]?{digit}+{e}?	{ return CONST_INT;}
[+-]?(({digit}+"."{digit}*)|({digit}*"."{digit}+)){e}?	{ return CONST_FLOAT; }		
["]([^"\\]|([\]["]))*["]		{ return CONST_STRING; }
{letter}(_|{letter}|{digit})*	{  
									id(yytext); 
						//			printf("id: %s\n", yytext); 
									return IDENTIFIER; 
								}
{Comment}	{ // comment(yytext); 
				printf("%s\n", yytext);
				}

"="		{ return '='; }
"+"		{ return '+'; }
"-"		{ return '-'; }
"*"		{ return '*'; }
"/"		{ return '/'; }
"||"	{ return OR; }
"&&"	{ return AND; }
"!"		{ return NOT; }
"{"		{ return '{'; }
"}"		{ return '}'; }
"["		{ return '['; }
"]"		{ return ']'; }
"("		{ return '('; }
")"		{ return ')'; }
";"		{ return ';'; }
","		{ return ','; }
"."		{ return '.'; }
"<"		{ return '<'; }
">"		{ return '>'; }
"#"		{ return '#'; }
":"		{ return ':'; }

%%

void id(char *str)
{
	symtab *ent;
	if ((ent = lookup(str)) == NULL) {
		insertID(str);
	}
	else {
		ent -> counter ++;
	}
}

void comment(char *yytext)
{
	comment_table[comment_index] =(char *)malloc(strlen(yytext) + 1);
	strncpy(comment_table[comment_index], yytext, strlen(yytext));
	comment_table[comment_index][strlen(yytext)] = '\0';
	printf("%s", comment_table[comment_index]);
	comment_index ++;
}

int main(int argc, char *argv[])
{
	argc --;
	argv ++;
	if (argc > 0) {
		yyin = fopen(argv[0], "r");
	}

	while (yylex())
		;
	printSymTab();
	fclose(yyin);
}
