#include <stdio.h>
extern char **environ; /* declare the external variable environ */

int main(void)
{
    char **s = environ; /* assign environ to a pointer s */
    for (; *s; s++) /* loop through the array of strings s */
    {
        printf("%s\n", *s); /* print each string */
    }
    return (0);
}
