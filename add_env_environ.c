#include <stdio.h>
extern char **environ; /* declare the external variable environ */

int main(int argc, char **argv, char **envp) /* use the third parameter of main */
{
    printf("Address of envp: %p\n", (void *)envp); /* print the address of envp */
    printf("Address of environ: %p\n", (void *)environ); /* print the address of environ */
    return (0);
}
