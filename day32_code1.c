 /*Arrays (1D)
 Merge two arrays from user input. */

#include <stdio.h>

int main() {
    int arr1[10], arr2[10], merged[20];
    int n1, n2, i, j;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);

    printf("Enter the elements of the first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    printf("Enter the elements of the second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merging the two arrays
    for (i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }
    for (j = 0; j < n2; j++) {
        merged[i + j] = arr2[j];
    }

    printf("Merged array: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}