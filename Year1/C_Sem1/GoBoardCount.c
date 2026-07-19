#include <stdio.h>
#include <string.h>

#define SIZE 9
#define BLACK 'X'
#define WHITE 'O'
#define EMPTY '.'

char board[SIZE][SIZE];
int black, white, count, isBlack, isWhite;

void takeInput() {
    black = white = 0;
    for (int i = 0; i < SIZE; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == BLACK) black++;
            if (board[i][j] == WHITE) white++;
        }
    }
}

void DFS(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] == '*') return;

    if (board[row][col] == EMPTY) {
        board[row][col] = '*';
        count++;
    } else {
        isBlack |= (board[row][col] == BLACK);
        isWhite |= (board[row][col] == WHITE);
        return;
    }

    DFS(row - 1, col);
    DFS(row + 1, col);
    DFS(row, col - 1);
    DFS(row, col + 1);
}

void countPoints() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                count = isBlack = isWhite = 0;
                DFS(i, j);
                if (isBlack && !isWhite) black += count;
                if (isWhite && !isBlack) white += count;
            }
        }
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        takeInput();
        countPoints();
        printf("Black %d White %d\n", black, white);
    }
    return 0;
}
