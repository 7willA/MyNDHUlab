#include <stdio.h>
#include <stdlib.h>

int main() {
    char operator;
    int result, operand;

    // Read the first operand
    scanf("%d", &result);

    while (scanf(" %c %d", &operator, &operand) == 2) {
        // Perform operation sequentially
        if (operator == '+') {
            result += operand;
        } else if (operator == '-') {
            result -= operand;
        } else if (operator == '*') {
            result *= operand;
        } else if (operator == '/') {
            if (operand != 0) {
                result /= operand;
            } else {
                printf("Error: Division by zero\n");
                return 1;
            }
        } else {
            printf("Error: Unsupported operator\n");
            return 1;
        }
    }

    // Print the result
    printf("%d\n", result);

    return 0;
}
