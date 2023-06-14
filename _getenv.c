#include <stdio.h>
extern char **environ; /* declare the external variable environ */

char *_getenv(const char *name) /* define the function */
{
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
