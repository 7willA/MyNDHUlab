#include <stdio.h>
#include <string.h>

#define MAX 100

char grid[MAX][MAX], temp[MAX][MAX];
int rows, cols;

int countNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == '1')
                count++;
        }
    }
    return count;
}

void simulate() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(i, j);
            temp[i][j] = (grid[i][j] == '1' && (neighbors == 2 || neighbors == 3)) || (grid[i][j] == '0' && neighbors == 3) ? '1' : '0';
        }
    }
    memcpy(grid, temp, sizeof(grid));
}

int main() {
    int n;
    scanf("%d", &n);
    rows = 0;
    while (scanf("%s", grid[rows]) != EOF) rows++;
    cols = strlen(grid[0]);

    while (n--) simulate();

    for (int i = 0; i < rows; i++) printf("%s\n", grid[i]);
    return 0;
}
