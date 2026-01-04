#include <stdio.h>

int main() {
    int row = 4;
    int col = 5;
    
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 6, 9, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 7, 0, 0}
    };

    int size = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }

    int sparseMatrix[size][3];
    int k = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("Row\tCol\tValue\n");
    printf("---\t---\t-----\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}