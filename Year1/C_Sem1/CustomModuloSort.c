#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;

int cmp(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    int mod1 = num1 % m;
    int mod2 = num2 % m;

    if (mod1 != mod2)
        return mod1 - mod2;

    int isNum1Odd = num1 % 2 != 0;
    int isNum2Odd = num2 % 2 != 0;

    if (isNum1Odd && isNum2Odd)
        return num2 - num1; // Larger odd number first
    if (!isNum1Odd && !isNum2Odd)
        return num1 - num2; // Smaller even number first

    return isNum1Odd - isNum2Odd; // Odd numbers come first
}

int main() {
    while (scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
        int q[n];
        memset(q, 0, sizeof(q));

        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }

        qsort(q, n, sizeof(int), cmp);

        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++) {
            printf("%d\n", q[i]);
        }
    }
    printf("0 0\n");

    return 0;
}
