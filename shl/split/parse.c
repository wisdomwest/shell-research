#include "main.h"

char **parse(char *line)
{
	char *copy = strdup(line);
	char *delim = "\t\r\n\a";
	int count = 0, i = 0;
	char *token = strtok(copy, delim);
	char **words;

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	words = malloc((count + 1) * sizeof(char *));
	strcpy(copy, line);
	token = strtok(copy, delim);
	while (token != NULL)
	{
		words[i] = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	words[i] = NULL;
	free(copy);
	return (words);
}
