int execute(char **tokens)
{
        pid_t pid, wpid;
        int status;
        char **envp = environ;
        char *path;

        pid = fork();
        if (pid == 0)
        {
                path = findpath(*tokens);
                if (path != NULL)
                {
                        if (execve(path, tokens, envp) == -1)
                        {
                                perror("hsh");
                        }
                }
                else
                {
                        fprintf(stderr, "hsh: command not found: %s\n", *tokens);
                }
                exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
                perror("hsh");
        }
        else
        {
                do
                {
                        wpid = waitpid(pid, &status, WUNTRACED);
                }
                while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        return (0);
}
