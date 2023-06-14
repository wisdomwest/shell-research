#include "main.h"

int main()
{
	int mode;

	while(mode)
	{
		char *line;
		char **parsed;
		
		mode = isatty(STDIN_FILENO);
		if (mode == 1)
			write(STDOUT_FILENO, "$ ", 2);
		line = readline();
		parsed = parse(line);

		if(parsed[0] != NULL)
			execute(parsed);
		free(parsed);
		free(line);
	}
}
