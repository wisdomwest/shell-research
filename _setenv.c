#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function that changes or adds an environment variable
int _setenv(const char *name, const char *value, int overwrite) {
  char *old_value; // The current value of the environment variable
  char *new_value; // The new value of the environment variable
  int result; // The result of putenv

  // Get the current value of the environment variable
  old_value = getenv(name);
  if (old_value == NULL) {
    // The environment variable does not exist, so create it
    overwrite = 1;
  }

  // Check if overwrite is allowed
  if (overwrite) {
    // Allocate memory for the new value string
    new_value = malloc(strlen(name) + strlen(value) + 2);
    if (new_value == NULL) {
      // Memory allocation failed, return -1
      return -1;
    }

    // Copy the name and value into the new string
    strcpy(new_value, name);
    strcat(new_value, "=");
    strcat(new_value, value);

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

  // Overwrite is not allowed and the environment variable exists, do nothing and return 0
  return 0;
}

