#include <stdio.h>

void spiralOrder(int rows, int cols, int matrix[rows][cols]) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;
        
        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;
        
        // Traverse from right to left along the bottom row 
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }
        
        // Traverse from bottom to top along the left column (if still in range)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

int main() {
    int rows, cols;

    // Input number of rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the elements in spiral order
    printf("Spiral Order: ");
    spiralOrder(rows, cols, matrix);
    printf("\n");

    return 0;
}
