#include <stdio.h>

int main() {
    int students;
    printf("How many students: ");
    scanf("%d", &students);
    int studentScores[students];

    // Initialize each element in the array to -1
    for (int i = 0; i < students; i++) {
        studentScores[i] = -1;
    }

    int studentNumber = -1;  // Initialize to an invalid value
    while (studentNumber != 0) {
        printf("\nEnter student number (1 – %d) or 0 to stop: ", students);
        scanf("%d", &studentNumber);

        if (studentNumber == 0) {
            break;
        } else if (studentNumber < 1 || studentNumber > students) {
            printf("Invalid student number!\n");
            continue;
        }

        int grade = -2;  // Initialize to an invalid value
        while (grade < -1 || grade > 5) {
            printf("Enter grade (0 – 5) for student %d or -1 to cancel: ", studentNumber);
            scanf("%d", &grade);

            if (grade >= -1 && grade <= 5) {
                studentScores[studentNumber - 1] = grade;
            } else {
                printf("Invalid grade!\n");
            }
        }
    }

    printf("\nStudent    Grade\n");
    for (int i = 0; i < students; i++) {
        if (studentScores[i] == -1) {
            printf("%-10d N/A\n", i + 1);
        } else {
            printf("%-10d %d\n", i + 1, studentScores[i]);
        }
    }

    return 0;
}
