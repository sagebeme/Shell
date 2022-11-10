#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int sage =1;

	while (sage == 1)
	{
		write(STDIO_FILENO, "$ ", 3);

		char *buffer;
		size_t buflen = 0;
		getline(&buffer,&buflen, stdin);

		write(STDIO_FILENO, buffer, strlen(buffer));
	}
}
