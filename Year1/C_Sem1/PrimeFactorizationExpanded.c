#include <stdio.h>

int main() {
    int num;

    while (1) {
        printf("Enter a number (0 to exit): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        printf("%d = ", num);

        // Handle the case of 2
        int first = 1; // Flag to check if it's the first factor
        while (num % 2 == 0) {
            if (!first) {
                printf(" * ");
            }
            printf("2");
            num /= 2;
            first = 0;
        }

        // Handle odd divisors
        for (int i = 3; i * i <= num; i += 2) {
            while (num % i == 0) {
                if (!first) {
                    printf(" * ");
                }
                printf("%d", i);
                num /= i;
                first = 0;
            }
        }

        // Print the last prime factor, if any
        if (num > 1) {
            if (!first) {
                printf(" * ");
            }
            printf("%d", num);
        }

        printf("\n");
    }

    return 0;
}