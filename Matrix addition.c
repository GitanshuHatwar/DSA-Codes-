#include <stdio.h>

int main() {
    int matrix1[3][3], matrix2[3][3], matrixSum[3][3];
    int i, j;

    printf("Enter elements of Matrix 1 (3x3):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("matrix1[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter elements of Matrix 2 (3x3):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("matrix2[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Matrix Addition Process
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nSum of Matrix 1 and Matrix 2:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", matrixSum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

