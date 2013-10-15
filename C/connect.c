#include <stdio.h>
#include <stdlib.h>

#define COL	6
#define	ROW		6

#define	PIECE_1		'O'
#define	PIECE_2		'X'
#define	PIECE_EPY	'-'
#define TOKEN_1 	1
#define	TOKEN_2		-1
#define	TOKEN_EPY	0

int main(int argc, char **argv)
{
	if (argc == 1) {
	}

	if (argc == 2) {
	}
	return 0;
}

void print_result(int i)
{
	if (i == WIN1)
		printf("Player 1 wins\n");
	else if (i == WIN2)
		printf("Player 2 wins\n");
	else 
		printf("Tie game\n");
	return;
}


int connect_4(void)
{
	int	flags;

	int	board[ROW][COL];
	
	for (int i = 0;i < ROW; i ++)
		for (j = 0; j < COL; j ++)
			board = TOKEN_EPY;

	while (1) {
		printf("Player 1, choose a col: ");
		getchar(

