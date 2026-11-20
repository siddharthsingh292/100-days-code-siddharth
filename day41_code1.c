//Perform diagonal traversal of a matrix.

#include <stdio.h>

int main() {
    int m, n, i, j, d;
    int a[100][100];

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the %d elements of the matrix (row by row):\n", m * n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Diagonal traversal of the matrix:\n");

    /* d = i + j runs from 0 to (m + n - 2) */
    for (d = 0; d <= m + n - 2; d++) {
        /* valid row range for this diagonal */
        int start = (d - (n - 1) > 0) ? d - (n - 1) : 0;
        int end   = (d < m - 1) ? d : m - 1;

        if (d % 2 == 1) {
            /* odd diagonal: top to bottom (row increasing) */
            for (i = start; i <= end; i++) {
                printf("%d ", a[i][d - i]);
            }
        } else {
            /* even diagonal: bottom to top (row decreasing) */
            for (i = end; i >= start; i--) {
                printf("%d ", a[i][d - i]);
            }
        }
    }
    printf("\n");

    return 0;
}