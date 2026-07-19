#include <stdio.h>

typedef struct {
    char studentID[20];
    int programming, programmingLab, calculus;
} Student;

int main() {
    int N;
    scanf("%d", &N);
    Student students[N];

    for (int i = 0; i < N; i++)
        scanf("%s %d %d %d", students[i].studentID, &students[i].programming, &students[i].programmingLab, &students[i].calculus);

    for (int i = 0; i < 3 && i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int totalI = students[i].programming + students[i].programmingLab + students[i].calculus;
            int totalJ = students[j].programming + students[j].programmingLab + students[j].calculus;
            if (totalJ > totalI) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
        printf("%s\n", students[i].studentID);
    }

    return 0;
}
