#include <stdio.h>
//This C program calculates the maximum cycle length for integers in a given range by using the Collatz conjecture.
int cycle_length(int n) { 
    int count = 1; 
    while (n != 1) { 
        if (n % 2 == 0) { 
            n = n/2;
        } else { 
            n = 3 * n + 1;
        }
        count++;
    }
    return count; 
}

int max_cycle_length(int i, int j){
    int start = i < j ? i : j;
    int end = i > j ? i : j;
    int max_length = 0;
    for (int num = start; num <= end; num++) {
        int length = cycle_length(num);
        if (length > max_length) {
            max_length = length;
        }
    }
    return max_length;
}
int main() {
    int i, j;

    while (scanf("%d %d", &i, &j) == 2) {
        int result = max_cycle_length(i, j);
        printf("%d %d %d\n", i, j, result);

    }
    return 0;
}
