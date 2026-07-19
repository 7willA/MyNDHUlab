//Maze

#include <stdio.h>

#define MAX_SIZE 100

int maze[MAX_SIZE][MAX_SIZE];  
int n;                   

// Direction a se deplacer: up, down, left, right
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function pr verifier si une position est valide
int is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0;
}

// Recursive function pour verifier le chemin
int find_path(int x, int y) {
    // If we reach the bottom-right corner, return Yes!
    if (x == n - 1 && y == n - 1) {
        return 1;
    }

    // MArquer la cellule comme deja visiter (le changer en 1)
    maze[x][y] = 1;

    // Essaie de deplacer dans les 4 directions
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        if (is_valid(nx, ny)) {  // verifie si le deplacement est valid
            if (find_path(nx, ny)) {  // verifie la nouvelle position
                return 1;  // If a path is found, return Yes
            }
        }
    }

    return 0;  // If no path is found, return No
}

int main() {
    // lire la taille du labyrinthe
    scanf("%d", &n);

    // Lecture du labyrinthe
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // commencer a (0, 0) et verifie s'il y'a un chemin a (n-1, n-1)
    if (find_path(0, 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
