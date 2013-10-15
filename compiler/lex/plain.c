/*************************************************************************
	> File Name: plain.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年07月10日 星期三 18时10分55秒
    > Describition: Basic parser, shows the structure but there's no 
				code generation
 ************************************************************************/

#include <stdio.h>
#include "lex.h"

void factor(void);
void term_prime(void);
void term(void);
void expression_prime(void);
void expression(void);

void 
statements()
{
	/* Statements	->	expression SEMI
	 *				|	expression SEMI statements
	 */

	expression();
	if (match(SEMI))
		advance();
	else 
		fprintf(stderr, "%d: Inserting missing semicolon\n", yylineno);
	if (!match(EOI))
		statements();	
}

void 
expression(void)
{
	/* Expression	-> term expression_prime */

	term();
	expression_prime();
}

void 
expression_prime(void)
{
	/* Expression_prime	-> PLUS term expression_prime 
	 *					|  epsilon
	 */
	
	if (match(PLUS)) {
		advance();
		term();
		expression_prime();
	}
}

void
term(void)
{
	/* Term	-> factor term_prime */

	factor();
	term_prime();
}

void 
term_prime(void)
{
	/* Term_prime	->	TIMES factor term_prime 
	 *				|	epsilon
	 */

	if (match(TIMES)) {
		advance();
		factor();
		term_prime();
	}
}

void 
factor(void)
{
	/* Factor -> NUM_OR_ID
	 *		  |  (expression)
	 */

	if (match(NUM_OR_ID)) {
		advance();
	}
	else if (match(LP)) {
		advance();
		expression();
		if (!match(RP))
			fprintf(stderr, "%d: Mismatched parenthesis\n", yylineno);
		advance();
	}
	else 
		fprintf(stderr, "%d Number or identifier expected\n", yylineno);
}


