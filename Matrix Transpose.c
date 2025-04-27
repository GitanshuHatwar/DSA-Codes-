#include <stdio.h>

int main() {
    int matrix1[3][3], matrixTranspose[3][3];
    int i, j;

    printf("Enter elements of Matrix 1 (3x3):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("matrix1[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Transpose Operation
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            matrixTranspose[j][i] = matrix1[i][j];
        }
    }

    printf("\nTranspose of Matrix 1:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", matrixTranspose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

