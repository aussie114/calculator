#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "tinyexpr.h"

/*
\033[A move up
\033[2K clear line
*/
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printf("%g\n", te_interp(argv[1], NULL));
		return 0;
	}
	puts("\nThis program evaluates your input\nas a mathamatical expression\n\nEnter an expression or q to quit....\n\n");
	char * input;

	while(1)
	{
		input = readline("> ");

		if (input[0] == 'q') { break; }
		printf("\033[A\033[2K\033[A%s = %g\n\n", input, te_interp(input, NULL));
		add_history(input);
		free(input);
	}
	return 0;
}
