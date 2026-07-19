#include <stdio.h>

int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) {
            break;
        }
        int tab[a];
        for (int i = 0; i < a; i++) {
            scanf("%d", &tab[i]);
        }

        int temp;
        for (int i = 0; i < a - 1; i++) {
            for (int j = 0; j < a - i - 1; j++) {
                int mod_j = tab[j] % b;
                int mod_j1 = tab[j + 1] % b;
                if (mod_j > mod_j1) {
                    temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                } else if (mod_j == mod_j1) {
                    if (tab[j] % 2 == 0 && tab[j + 1] % 2 != 0) {
                        temp = tab[j];
                        tab[j] = tab[j + 1];
                        tab[j + 1] = temp;
                    } else if (tab[j] % 2 != 0 && tab[j + 1] % 2 != 0) {
                        if (tab[j] < tab[j + 1]) {
                            temp = tab[j];
                            tab[j] = tab[j + 1];
                            tab[j + 1] = temp;
                        }
                    } else if (tab[j] % 2 == 0 && tab[j + 1] % 2 == 0) {
                        if (tab[j] > tab[j + 1]) {
                            temp = tab[j];
                            tab[j] = tab[j + 1];
                            tab[j + 1] = temp;
                        }
                    }
                }
            }
        }

        printf("%d %d\n", a, b);
        for (int i = 0; i < a; i++) {
            printf("%d\n", tab[i]);
        }
    }
    printf("0 0\n");
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

// Custom comparator function for sorting
int compare(const void *a, const void *b, void *mod) {
    int mod_val = *(int *)mod;
    int x = *(int *)a, y = *(int *)b;
    int mod_x = x % mod_val, mod_y = y % mod_val;

    // Compare by modulus
    if (mod_x != mod_y) 
        return mod_x - mod_y;

    // Odd numbers before even numbers
    if ((x % 2 != 0) && (y % 2 == 0)) 
        return -1;
    if ((x % 2 == 0) && (y % 2 != 0)) 
        return 1;

    // Among odd numbers: larger first
    if ((x % 2 != 0) && (y % 2 != 0)) 
        return y - x;

    // Among even numbers: smaller first
    if ((x % 2 == 0) && (y % 2 == 0)) 
        return x - y;

    return 0;
}

int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;

        int tab[a];
        for (int i = 0; i < a; i++) 
            scanf("%d", &tab[i]);

        qsort_r(tab, a, sizeof(int), compare, &b);

        printf("%d %d\n", a, b);
        for (int i = 0; i < a; i++) 
            printf("%d\n", tab[i]);
    }
    printf("0 0\n");
    return 0;
}
*/