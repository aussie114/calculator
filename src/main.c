#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "tinyexpr.h"

/*
\033[A move up
\033[2K clear line
*/
int main(void)
{
	puts("\nThis program evaluates your input\nas a mathamatical expression\n\nEnter an expression or q to quit...\n\n");
	char * input;

	while(1)
	{
		input = readline("> ");
		if (input[0] == 'q') {break;}
		printf(
			"\033[A"  // move
			"\033[2K" // clear
			"\033[A"  // move
			"%s = %g\n\n", input, te_interp(input, NULL));
		add_history(input);
		free(input);
	}
	return 0;
}
