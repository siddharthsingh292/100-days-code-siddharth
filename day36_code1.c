//Read and print a matrix.
#include <stdio.h>

int main() {
    int r, c;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d", a[i][j]);
            if (j < c - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}