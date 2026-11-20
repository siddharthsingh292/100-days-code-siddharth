//Check if the elements on the diagonal of a matrix are distinct.

#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);

    int a[100][100];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Main diagonal length (works even if the matrix isn't square)
    int d = (n < m) ? n : m;

    int distinct = 1;
    for (int i = 0; i < d && distinct; i++) {
        for (int j = i + 1; j < d; j++) {
            if (a[i][i] == a[j][j]) {
                distinct = 0;
                break;
            }
        }
    }

    if (distinct)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}