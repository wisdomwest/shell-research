#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the PID of the parent process
 * Return: 0 on success
 */
int main(void)
{
    pid_t ppid;

    ppid = getppid(); /* get the PID of the parent process */
    printf("%u\n", ppid); /* print the PID of the parent process */
    return (0);
}
