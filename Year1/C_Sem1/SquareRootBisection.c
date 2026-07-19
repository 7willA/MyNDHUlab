#include <stdio.h>

int main() {
    int n;
    double a, b, c,sqrt_n;

    scanf("%d", &n);

    if (n <= 0) {
        
        return 1;
    }

    a = 0;
    b = n;

    for (int i = 0; i < 100; i++) {
        c = (a + b) / 2;
        if (c * c >= n) {
            b = c;
        } else {
            a = c;
        }
    }

     sqrt_n = (a + b) / 2;
    printf("%.4f\n", sqrt_n);

    return 0;
}