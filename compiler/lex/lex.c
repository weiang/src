/*************************************************************************
	> File Name: lex.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年07月10日 星期三 17时31分54秒
    > Describition: 
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include "lex.h"

char	*yytext		= "";	/* Lexeme (not '\0' terminated) */
int		yyleng		= 0;	/* Lexeme length */
int		yylineno	= 0;	/* Input line number */

int 
lex(void)
{
	static char	input_buffer[128];
	char		*current;
	
	current = yytext + yyleng;

	while (1) {
		while (!*current) {
			/* Get new lines, skipping any leading white space on the line,
			 * until a nonblank line is found.
			 */

			current = input_buffer;
			if (!gets(input_buffer)) {
				*current = '\0';
				return EOI;
			}
			++ yylineno;

			while (isspace(*current))
				++ current;
		}
		
		for (; *current; ++ current) {
			/* Get the next token */
			yytext = current;
			yyleng = 1;
			switch (*current) {
				case EOF: return EOI;
				case ';': return SEMI;
				case '+': return PLUS;
				case '*': return TIMES;
				case '(': return LP;
				case ')': return RP;

				case '\n':
				case '\t':
				case ' ': break;
				default:
					if (!isalnum(*current))
							fprintf(stderr, "Ignoring illegal input <%c>\n", *current);
					else {
						while (isalnum(*current)) 
							++ current;
						yyleng = current - yytext;
						return NUM_OR_ID;
					}
					break;
			}
		}
	}
}

static int Lookahead = -1;	/* Lookahead token */

int
match(int token)
{
	/* 
	 * Return ture if "token" match the current lookahead symbol. 
	 */
	
	if (Lookahead == -1)
		Lookahead = lex();
	return token == Lookahead;
}

void
advance(void)
{
	/* Advance the lookahead to the next input symbol. */
	
	Lookahead = lex();
}


