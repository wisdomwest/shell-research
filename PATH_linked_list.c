#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the linked list node
typedef struct Node {
  char *data; // The directory name
  struct Node *next; // The pointer to the next node
} Node;

// Define a function that builds a linked list of the PATH directories
Node *build_path_list() {
  char *path; // The PATH environment variable
  char *token; // The current directory name
  Node *head; // The head of the linked list
  Node *node; // The current node

  // Get the value of the PATH environment variable
  path = getenv("PATH");
  if (path == NULL) {
    return NULL; // Return NULL if PATH is not set
  }

  // Initialize the head of the list to NULL
  head = NULL;

  // Split the path by colon and get each directory name
  token = strtok(path, ":");
  while (token != NULL) {
    // Allocate memory for a new node
    node = malloc(sizeof(Node));
    if (node == NULL) {
      return NULL; // Return NULL if allocation fails
    }

    // Make a copy of the token and assign it to the node's data
    node->data = strdup(token);
    if (node->data == NULL) {
      return NULL; // Return NULL if duplication fails
    }

    // Insert the node at the beginning of the list
    node->next = head;
    head = node;

    // Get the next token
    token = strtok(NULL, ":");
  }

  // Return the head of the list
  return head;
}

