//Insert an element in a sorted array at the appropriate position.

/*
Sample Test Cases:
Input 1:
5
1 2 4 5 6
3
Output 1:
1 2 3 4 5 6

*/
#include <stdio.h>

int main() {
    int n, key;
    int a[1001];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &key);

    // Shift larger elements one step right
    int i = n - 1;
    while (i >= 0 && a[i] > key) {
        a[i + 1] = a[i];
        i--;
    }

    // Place the key in the gap
    a[i + 1] = key;
    n++;

    printf("Array after insertion: ");
    for (int j = 0; j < n; j++) {
        if (j > 0)
            printf(" ");
        printf("%d", a[j]);
    }
    printf("\n");

    return 0;
}