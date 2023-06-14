#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function that deletes an environment variable
int _unsetenv(const char *name) {
  char *new_value; // The new value of the environment variable
  int result; // The result of putenv

  // Allocate memory for the new value string
  new_value = malloc(strlen(name) + 2);
  if (new_value == NULL) {
    // Memory allocation failed, return -1
    return -1;
  }

  // Copy the name and an equal sign into the new string
  strcpy(new_value, name);
  strcat(new_value, "=");

  // Set the new value for the environment variable
  result = putenv(new_value);
  if (result != 0) {
    // putenv failed, free the memory and return -1
    free(new_value);
    return -1;
  }

  // Return 0 on success
  return 0;
}
