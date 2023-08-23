#include <stdio.h>

int main() {
    // Declare variables
    double incomes[12], taxes[12];
    double taxRate, taxRateOverLimit, incomeLimit;
    double totalIncome = 0.0;

    // Get tax rates and income limit from the user
    printf("Enter tax rate: ");
    scanf("%lf", &taxRate);
    printf("Enter income limit: ");
    scanf("%lf", &incomeLimit);
    printf("Enter tax rate for income over the limit: ");
    scanf("%lf", &taxRateOverLimit);

    // Get monthly incomes from the user
    for (int i = 0; i < 12; i++) {
        printf("Enter income for month %d: ", i + 1);
        scanf("%lf", &incomes[i]);
    }

    // Calculate the tax for each month
    for (int i = 0; i < 12; i++) {
        totalIncome += incomes[i];
        if (totalIncome <= incomeLimit) {
            taxes[i] = incomes[i] * taxRate / 100.0;
        } else if (totalIncome - incomes[i] < incomeLimit) {
            // This month's income crosses the limit
            double taxableAtLowerRate = incomeLimit - (totalIncome - incomes[i]);
            double taxableAtHigherRate = incomes[i] - taxableAtLowerRate;
            taxes[i] = taxableAtLowerRate * taxRate / 100.0 + taxableAtHigherRate * taxRateOverLimit / 100.0;
        } else {
            taxes[i] = incomes[i] * taxRateOverLimit / 100.0;
        }
    }

// Print the results
    printf("month  income    tax\n");
    for (int i = 0; i < 12; i++) {
        printf("%-5d %8.2lf %8.2lf\n", i + 1, incomes[i], taxes[i]);
    }


    return 0;
}
