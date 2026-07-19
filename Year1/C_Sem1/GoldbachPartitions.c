#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    
    if (n < 4 || n > 32766 || n % 2 != 0) {
        printf("Invalid input");
        return 1;
    }

    int count = 0;

   
    for (int p1 = 2; p1 <= n / 2; p1++) {
        int numPrime = 1; 
        for (int i = 2; i * i <= p1; i++) {
            if (p1 % i == 0) {
                numPrime = 0; 
                break;
            }
        }

        if (numPrime) {
            int p2 = n - p1; 
            int numPrime2 = 1; 
            for (int i = 2; i * i <= p2; i++) {
                if (p2 % i == 0) {
                    numPrime2 = 0; 
                    break;
                }
            }

            if (numPrime2) {
                count++;
            }
        }
    }

    
    printf("%d\n", count);
    
    return 0;
}