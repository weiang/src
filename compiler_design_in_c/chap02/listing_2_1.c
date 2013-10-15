/*************************************************************************
	> File Name: listing_2_1.c
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: Thu, Jul 25, 2013  3:29:39 PM
    > Describition:	P36 Listing 2.1.Using a Stack for Multiple-Character Pushback 
 ************************************************************************/

#include <stdio.h>
#define SIZE 128	/* Maximum number of pushed-back characters */

/* Pbackbuf is the push-back stack.
 * Pbackp	is the stack pointer. The stack grows down, so a push is:
 *			*--Pbackp=c	and a pop is:	c=*Pbackp++
 * get()	evaluates to the next input character, either popping it off the 
 *			stack (if it's not empty) or by calling getc().
 * ugetc(c)	pushes c back. It evaluates to c if successful, or to -1 if the 
 *			pushback stack was full.
 */

int Pbackbuf[SIZE];

#define get(stream) (Pbackp < &Pbackbuf[SIZE] ? *Pbackp++ : getc(stream)	)
#define ungetc(c)	(Pbackp <= Pbackbuf		  ?	-1		  : (*--Pbackp=(c)	)

void	ungets(char *start, int n);
{
	/* Push back the last n characters of the string by working backwards
	 * through the string
	 */

	char *p = start + strlen(start);	/* Find the end of the string. */

	while (--p >= start && --n >= 0)
		if (ungetc(*p) == -1)
			fprintf(stderr, "Pushback-stack overflow\n");
}			

