#include <stdio.h>

int main() {
    int students;
    printf("How many students? ");
    scanf("%d", &students);
    int studentScores[students];

    for (int i = 0; i < students; i++) {
        studentScores[i] = -1;
    }



    return 0;
}
