#include <stdio.h> //
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int row, col, count = 0;
    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &row, &col);
    int** matrix = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    int** transpose = (int**)malloc(col * sizeof(int*));
    for (int i = 0; i < col; i++) {
        transpose[i] = (int*)malloc(count * sizeof(int));
    }

    int* row_ptr = (int*)malloc((count + 1) * sizeof(int));
    int* col_ind = (int*)malloc(count * sizeof(int));
    int* values = (int*)malloc(count * sizeof(int));

    row_ptr[0] = 0;
    int index = 0;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            if (matrix[i][j] != 0) {
                transpose[j][index] = matrix[i][j];
                values[index] = matrix[i][j];
                col_ind[index] = i;
                index++;
            }
        }
        row_ptr[j + 1] = index;
    }

    printf("The transpose matrix is:\n");
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < count; i++) {
            if (col_ind[i] == j) {
                transpose[j][i] = values[i];
                printf("%d ", transpose[j][i]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < col; i++) {
        free(transpose[i]);
    }
    free(transpose);
    free(row_ptr);
    free(col_ind);
    free(values);

    return 0;
}
