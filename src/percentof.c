#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	if (argc > 2)
	{
		double x = strtod(argv[1], NULL);
		double y = strtod(argv[2], NULL);
		printf("%g%% of %g = %g\n", x, y, y * (x / 100) );
	}
	else
	{
		puts("Usages:\n\tpercentof x y");
	}
    return 0;
}
