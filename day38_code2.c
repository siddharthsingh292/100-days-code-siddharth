//Check if a matrix is symmetric.

#include <stdio.h>

int main() {
    int r, c;

    printf("Enter rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    // A non-square matrix can't be symmetric
    if (r != c) {
        printf("The matrix is not symmetric: False\n");
        return 0;
    }

    // Compare a[i][j] with a[j][i]
    for (int i = 0; i < r; i++) {
        for (int j = i + 1; j < c; j++) {
            if (a[i][j] != a[j][i]) {
                printf("The matrix is not symmetric: False\n");
                return 0;
            }
        }
    }

    printf("The matrix is symmetric: True\n");
    return 0;
}