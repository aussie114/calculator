#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tinyexpr.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() 
{
	puts("\n\n\n\n\n\n\n\n");
	char * input = NULL;
		
	while(1)
	{
		puts("――――――――――――――――――――――――――――――");
		input = readline("> ");

		if (!input || strcmp(input, "quit") == 0 || strcmp(input, "q") == 0) break;

		add_history(input);
		printf( "\033[1A" // Move up
				"\033[2K" // Clear
				"\033[1A" // Move up
				"\033[2K" // Clear
				"%s = %g\n", input, te_interp(input, 0));
		free(input);
	}

	return 0;
}
