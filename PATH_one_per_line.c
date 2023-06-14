#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_getenv(const char *name); /* declare the function to get an environment variable */
void print_path(char *path); /* declare the function to print each directory in the path */

int main(void)
{
    char *path; /* declare a pointer to hold the path variable */

    path = _getenv("PATH"); /* get the value of the path variable */
    if (path == NULL) /* check if it is NULL */
    {
        printf("PATH not found\n"); /* print an error message */
        return (1); /* exit with status 1 */
    }
    print_path(path); /* print each directory in the path */
    return (0); /* exit with status 0 */
}

char *_getenv(const char *name) /* define the function to get an environment variable */
{
    extern char **environ; /* declare the external variable environ */
    char **s = environ; /* assign environ to a pointer s */
    int i = 0; /* declare a counter variable */

    while (s[i] != NULL) /* loop through the array of strings s */
    {
        if (strncmp(s[i], name, strlen(name)) == 0) /* compare the name with the current string */
        {
            return (s[i] + strlen(name) + 1); /* return the value after the '=' sign */
        }
        i++; /* increment the counter */
    }
    return (NULL); /* return NULL if not found */
}

void print_path(char *path) /* define the function to print each directory in the path */
{
    char *token; /* declare a pointer to hold each token */

    token = strtok(path, ":"); /* get the first token separated by ':' */
    while (token != NULL) /* loop until no more tokens are found */
    {
        printf("%s\n", token); /* print the token */
        token = strtok(NULL, ":"); /* get the next token separated by ':' */
    }
}
