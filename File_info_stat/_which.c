#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - looks for files in the current PATH
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    char *path;
    char *token;
    char *file;
    char buffer[1024];

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        return (1);
    }

    path = getenv("PATH"); /* get the PATH environment variable */
    if (path == NULL)
    {
        perror("getenv");
        return (1);
    }

    path = strdup(path); /* make a copy of the PATH string */
    if (path == NULL)
    {
        perror("strdup");
        return (1);
    }

    for (int i = 1; i < argc; i++) /* loop through the filenames */
    {
        file = argv[i];
        token = strtok(path, ":"); /* split the PATH by : */
        while (token != NULL) /* loop through the directories in PATH */
        {
            snprintf(buffer, sizeof(buffer), "%s/%s", token, file); /* append filename to directory */
            if (access(buffer, F_OK) == 0) /* check if file exists and is readable */
            {
                printf("%s\n", buffer); /* print the file path */
                break; /* stop searching for this file */
            }
            token = strtok(NULL, ":"); /* get the next directory in PATH */
        }
        if (token == NULL) /* file not found in any directory */
        {
            fprintf(stderr, "%s: command not found\n", file);
        }
    }

    free(path); /* free the copy of PATH */
    return (0);
}
