#include <stdio.h>
#include <stdbool.h>
#define SIZE 19

bool check_winner(char board[SIZE][SIZE], char player) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == player) {
            
                if (j + 4 < SIZE &&
                    board[i][j + 1] == player &&
                    board[i][j + 2] == player &&
                    board[i][j + 3] == player &&
                    board[i][j + 4] == player) {
                    return true;
                }
                
                if (i + 4 < SIZE &&
                    board[i + 1][j] == player &&
                    board[i + 2][j] == player &&
                    board[i + 3][j] == player &&
                    board[i + 4][j] == player) {
                    return true;
                }
                
                if (i + 4 < SIZE && j + 4 < SIZE &&
                    board[i + 1][j + 1] == player &&
                    board[i + 2][j + 2] == player &&
                    board[i + 3][j + 3] == player &&
                    board[i + 4][j + 4] == player) {
                    return true;
                }
                
                if (i + 4 < SIZE && j - 4 >= 0 &&
                    board[i + 1][j - 1] == player &&
                    board[i + 2][j - 2] == player &&
                    board[i + 3][j - 3] == player &&
                    board[i + 4][j - 4] == player) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char board[SIZE][SIZE];

    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf(" %c", &board[i][j]); 
        }
    }

    if (check_winner(board, 'O')) {
        printf("White\n");
    } else if (check_winner(board, 'X')) {
        printf("Black\n");
    } else {
        printf("No winner\n");
    }

    return 0;
}
 
 