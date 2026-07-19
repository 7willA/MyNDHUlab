#include <stdio.h>

#define MAX 100

int main() {
    char field[MAX][MAX];
    int n, m, fieldNumber = 0;

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }

        getchar(); // Consume the newline character
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &field[i][j]);
            }
        }

        if (fieldNumber > 0) {
            printf("\n");
        }
        printf("Field #%d:\n", ++fieldNumber);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*') {
                    printf("*");
                } else {
                    int count = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ni = i + di, nj = j + dj;
                            if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] == '*') {
                                count++;
                            }
                        }
                    }
                    printf("%d", count);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
