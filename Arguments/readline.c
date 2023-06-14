#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints "$ ", wait for the user to enter a command, prints it on the next line
 * Return: 0 on success, 1 on error
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1) /* loop until EOF or error */
    {
        printf("$ "); /* print the prompt */
        nread = getline(&line, &len, stdin); /* read a line from stdin */
        if (nread == -1) /* check for error or EOF */
        {
            break; /* exit the loop */
        }
        printf("%s", line); /* print the line */
    }
    free(line); /* free the allocated buffer */
    if (nread == -1 && !feof(stdin)) /* check for error */
    {
        perror("getline"); /* print error message */
        return (1); /* return with error code */
    }
    return (0); /* return with success code */
}
