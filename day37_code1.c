// Find the sum of each row of a matrix and store it in an array.
#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];
    int sum[r];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++) {
        sum[i] = 0;
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
    }

    printf("Row sums: ");
    for (int i = 0; i < r; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");

    return 0;
}