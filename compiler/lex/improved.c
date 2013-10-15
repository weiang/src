/*************************************************************************
	> File Name: improve.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年07月10日 星期三 18时49分09秒
    > Describition:	Revised parser
 ************************************************************************/

#include <stdio.h>
#include "lex.h"
#include <stdarg.h>

#define MAXFIRST	16
#define SYNCH		SEMI

int legal_lookahead(int, ...);
void factor(void);
void term(void);
void expression(void);

void
statements()
{
	/* Statements -> expression SEMI | expression SEMI statements */

	while (!match(EOI)) {
		expression();

		if (match(SEMI))
			advance();
		else 
			fprintf(stderr, "%d: Inserting missing semicolon\n", yylineno);
	}
}

void 
expression(void)
{
	if (!legal_lookahead(NUM_OR_ID, LP, 0))
		return;

	term();
	while (match(PLUS)) {
		advance();
		term();
	}
}

void
term(void)
{
	if (!legal_lookahead(NUM_OR_ID, LP, 0))
		return;

	factor();
	while(match(TIMES)) {
		advance();
		factor();
	}
}

void
factor(void)
{
	if (match(NUM_OR_ID)) {
		advance();
	}
	else if (match(LP)) {
		advance();
		expression();
		if (match(RP))
			advance();
		else 
			fprintf(stderr, "%d: Mismatched parenthesis\n", yylineno);
	}
	else 
		fprintf(stderr, "%d: Nummber of identifier expected\n", yylineno);
}

int
legal_lookahead(int first, ...)
{
	/* Simple error detection and recovery. Arguements are a 0-terminated list of 
	 * those tokens that can legitimately come next in the input. If the list is
	 * empty, the end of file must come next. Print an error message if 
	 * necessary. Error recovery is performed by discarding all input symbols
	 * until one that's in the input list is found
	 *
	 * Return ture if there's no error or if we recovered from the error,
	 * false if we can't recover.
	 */

	int	retval = 0, tok;
	int error_printed = 0;
	int arguements[MAXFIRST];
	int *p = arguements;
	int *current;
	va_list args;
	
	va_start(args, first);

	if (!first) {
		if (match(EOI))
			retval = 1;
	}
	else {
		*p ++ = first;
		while ((tok = va_arg(args, int)) && p < &arguements[MAXFIRST]) 
			*p ++ = tok;
		while (!match(SYNCH)) {
			for (current = arguements; current != p; current ++)
				if (match(*current)) {
					retval = 1;
					goto exit;
				}
			if (error_printed == 0) {
				fprintf(stderr, "Line %d: Syntax error\n", yylineno);
				error_printed = 1;
			}
			advance();
		}
	}

exit:
	va_end(args);
	return retval;
}

				
