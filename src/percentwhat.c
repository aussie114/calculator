#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	if (argc > 2)
	{
		double x = strtod(argv[1], NULL);
		double y = strtod(argv[2], NULL);
		printf("%g = %g%% of %g\n", x, x / (y / 100), y);
	}
	else
	{
		puts("Usages:\n\tpercentwhat x y");
	}
    return 0;
}
