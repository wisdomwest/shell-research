#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function that splits a string by a delimiter and returns an array of words
char **split_string(char *str, char *delim)
{
    // Copy the original string to avoid modifying it
    char *copy = strdup(str);

    // Count the number of words in the string
    int count = 0;
    char *token = strtok(copy, delim);
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, delim);
    }

    // Allocate memory for the array of words
    char **words = malloc((count + 1) * sizeof(char *));

    // Split the string again and store each word in the array
    strcpy(copy, str); // Restore the original string
    int i = 0;
    token = strtok(copy, delim);
    while (token != NULL)
    {
        words[i] = strdup(token); // Copy each word
        i++;
        token = strtok(NULL, delim);
    }
    words[i] = NULL; // Mark the end of the array

    // Free the copied string and return the array
    free(copy);
    return words;
}
