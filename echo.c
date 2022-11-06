#include <stdio.h>
/**
 *
 *main - loop through input
 *
 *Return 0;
 *
 */

int main(void)
{
	char c;
	
	while ((c=getchar())!='\n')
	{
		putchar(c);
	}
	return (0);
}
