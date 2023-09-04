#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_menu();
int get_choice();
void roll_d6();
void roll_d10();

int main() {
    srand(time(NULL));

    int choice;
    do {
        print_menu();
        choice = get_choice();

        switch (choice) {
            case 1:
                roll_d6();
                break;
            case 2:
                roll_d10();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}


void print_menu() {
    printf("\nSelect an operation:\n");
    printf("1. Roll D6\n");
    printf("2. Roll D10\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

int get_choice() {
    int choice;

    if (scanf("%d", &choice) != 1) {
        printf("Error: Please enter a valid number.\n");
        while (getchar() != '\n');
        return -1;
    }

    return choice;
}

void roll_d6() {
    int result = (rand() % 6) + 1;
    printf("D6: %d\n", result);
}

void roll_d10() {
    int result = (rand() % 10) + 1;
    printf("D10: %d\n", result);
}
