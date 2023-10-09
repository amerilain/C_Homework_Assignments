#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

int main() {
    char input[50];
    nnode *head = NULL, *current, *temp;

    while (1) {
        printf("Enter a number or 'end' to stop: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "end") == 0) {
            break;
        }

        int num;
        if (sscanf(input, "%d", &num) != 1) {
            printf("Error: Invalid input. Please enter a number or 'end'.\n");
            continue;
        }

        // Create a new node
        nnode *newNode = (nnode *)malloc(sizeof(nnode));
        newNode->number = num;
        newNode->next = NULL;

        // Add the new node to the linked list
        if (head == NULL) {
            head = newNode;
        } else {
            current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Print the numbers
    printf("Entered numbers:\n");
    current = head;
    while (current != NULL) {
        printf("%d\n", current->number);
        current = current->next;
    }

    // Free the allocated memory
    current = head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
