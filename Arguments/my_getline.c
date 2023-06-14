#include <stdio.h>
#include <stdlib.h>

// A custom getline function that returns the number of characters read
// or -1 on error or end of file
ssize_t my_getline(char **line, size_t *size, FILE *stream)
{
    // Check if the parameters are valid
    if (line == NULL || size == NULL || stream == NULL)
    {
        return -1;
    }

    // Allocate an initial buffer if needed
    if (*line == NULL || *size == 0)
    {
        *line = malloc(128);
        if (*line == NULL)
        {
            return -1;
        }
        *size = 128;
    }

    // Read characters from the stream until newline or end of file
    size_t len = 0; // The length of the line
    int c; // The current character
    while ((c = getc(stream)) != '\n' && c != EOF)
    {
        // If the buffer is full, resize it
        if (len == *size - 1)
        {
            char *new_line = realloc(*line, *size * 2);
            if (new_line == NULL)
            {
                return -1;
            }
            *line = new_line;
            *size *= 2;
        }

        // Store the character in the buffer
        (*line)[len] = (char) c;
        len++;
    }

    // If no characters were read, return -1
    if (len == 0 && c == EOF)
    {
        return -1;
    }

    // Null-terminate the buffer and return the length
    (*line)[len] = '\0';
    return (ssize_t) len;
}
