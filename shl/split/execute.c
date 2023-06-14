#include "main.h"

int execute(char **args)
{
        if (args[0] == NULL)
        {
                return (1);
        }
        return (launch(args));
}
int launch(char **args)
{
        pid_t child_pid;
        int status;
        child_pid = fork();

        if (child_pid == 0)
        {
                execvp(args[0], args);
                perror(args[0]);
                exit(1);
        }
        else if (child_pid > 0)
        {
                int status;
                do {
                        waitpid(child_pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        } else {
                perror(args[0]);
        }
}
