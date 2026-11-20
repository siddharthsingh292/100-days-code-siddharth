//Multiply two matrices.
#include <stdio.h>

int main() {
    int r1, c1, r2, c2, i, j, k;
    int a[50][50], b[50][50], c[50][50];

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the %d elements of the first matrix (row by row):\n", r1 * c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    /* multiplication is possible only if columns of A == rows of B */
    if (c1 != r2) {
        printf("Multiplication not possible: columns of the first matrix must equal rows of the second.\n");
        return 0;
    }

    printf("Enter the %d elements of the second matrix (row by row):\n", r2 * c2);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    /* c[i][j] = sum of a[i][k] * b[k][j] for k = 0..c1-1 */
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Product of the two matrices:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}