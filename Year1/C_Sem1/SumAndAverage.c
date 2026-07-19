#include <stdio.h>

int main() {
    int N, num, sum = 0;
    float average;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        sum += num;
    }

    average = (float)sum / N;

    printf("%d %.2f\n", sum, average);

    return 0;
}