/*************************************************************************
	> File Name: lex.h
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2013年07月10日 星期三 16时03分13秒
    > Describition: 
 ************************************************************************/
#ifndef _LEX_H_
#define _LEX_H_

#define EOI		0	/* End of input stream */
#define SEMI	1	/* ; */
#define PLUS	2	/* + */
#define TIMES	3	/* * */
#define LP		4	/* ( */
#define RP		5	/* ) */
#define NUM_OR_ID	6	/* Number or identifier */

extern char	*yytext;	/* Defined in lex.c */
extern int	yyleng;
extern int	yylineno;

extern void vdvance();
extern int match(int);

#endif /* _LEX_H_ */

