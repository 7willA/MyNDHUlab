#include <stdio.h>

int main() {
    int rows, cols, nonZeroCount;

    scanf("%d %d %d", &rows, &cols, &nonZeroCount);

    // Initialiser la matrice 2D remplie de zéros
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0; // Remplissage initial avec des zéros
        }
    }

    // Étape 2 : Lire les éléments non nuls et les insérer dans la matrice
    printf("Entrez les elements non nuls (ligne, colonne, valeur) :\n");
    for (int i = 0; i < nonZeroCount; i++) {
        int r, c, value;
        scanf("%d %d %d", &r, &c, &value);

        // Placer la valeur dans la matrice (indexation à partir de 0)
        matrix[r][c] = value;
    }

    // Étape 3 : Afficher la matrice reconstruite
    printf("La matrice originale est :\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}