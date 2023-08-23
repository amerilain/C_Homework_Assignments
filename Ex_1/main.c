#include <stdio.h>

int main() {
    double busPrice, taxiPrice, money;

    // Ask user to enter the price of a bus ticket
    printf("Enter price of bus ticket: ");
    scanf("%lf", &busPrice);

    // Ask user to enter the price of a taxi trip
    printf("Enter price of taxi: ");
    scanf("%lf", &taxiPrice);

    // Step 3: Ask user to enter how much money they has
    printf("How much money do you have: ");
    scanf("%lf", &money);

    while (1) {
        // Display remaining money and ask user to choose taxi or bus
        printf("You have %.2lf euros left.\n", money);
        printf("Do you want to take\n");
        printf("1) bus (%.2lf euros)\n", busPrice);
        printf("2) taxi (%.2lf euros)\n", taxiPrice);

        int choice;
        printf("Enter your selection: ");
        scanf("%d", &choice);

        // Check if the user has enough money for the selected trip
        if (choice == 1) {
            if (money >= busPrice) {
                printf("You chose bus.\n");
                money -= busPrice;
            } else {
                printf("You don’t have enough money for bus.\n");
                break;
            }
        } else if (choice == 2) {
            if (money >= taxiPrice) {
                printf("You chose taxi.\n");
                money -= taxiPrice;
            } else {
                printf("You don’t have enough money for taxi.\n");
                continue;
            }
        } else {
            printf("Invalid selection.\n");
            continue;
        }
    }

    // If the user doesn't have enough for either option, tell them to walk
    if (money < busPrice && money < taxiPrice) {
        printf("You need to walk. Bye\n");
    }

    return 0;
}
