#include "main.h"

char *readline(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t length;

	length = getline(&line, &size, stdin);
	if (length < 0)
	{
		perror("hsh");
		exit (1);
	}
	return (line);
}
