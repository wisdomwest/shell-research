#include <stdio.h>

/**
 * main - prints all the arguments
 * @av: array of arguments
 * Return: 0 on success
 */
int main(char **av)
{
    while (*av) /* loop until av is NULL */
    {
        printf("%s\n", *av); /* print the current argument */
        av++; /* move to the next argument */
    }
    return (0);
}
