#include <stdio.h>

int main() {
    int a, b;


    scanf("%d %d", &a, &b);


    if (b == 0) {
        printf(" Division by zero is not allowed.\n");
        return 1;
    }

    int sum = a + b;
    int diff = a - b;
    int prod = a * b;
    int quotient = a / b;
    int modulo = a % b;

    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, diff);
    printf("%d * %d = %d\n", a, b, prod);
    printf("%d / %d = %d\n", a, b, quotient);
    printf("%d %% %d = %d\n", a, b, modulo);

    return 0;
}
