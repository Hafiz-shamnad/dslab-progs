#include <stdio.h>

int sparseBuilder(int arr[][100], int row, int col) {
    int tuple[100][3], nonzero = 0, k = 1;
    tuple[0][0] = row;
    tuple[0][1] = col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                nonzero++;
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = arr[i][j];
                k++;
            }
        }
    }
    tuple[0][2] = nonzero;

    printf("\nSparse Matrix:\n");
    for (int i = 0; i <= nonzero; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int arr[100][100], row, col;
    int choice;

    printf("Enter the Number of rows: ");
    scanf("%d", &row);
    printf("Enter the Number of columns: ");
    scanf("%d", &col);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nMatrix successfully created!\n");
    printf("Inputed Matrix : \n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t ", arr[i][j]);
        }
        printf("\n");
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Sparse Matrix\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sparseBuilder(arr, row, col);
                break;
            case 2:
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
