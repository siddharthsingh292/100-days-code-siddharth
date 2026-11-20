#include <stdio.h>
#include <stdlib.h>

/* Brute force: for each element, scan to its left for the first greater element.
   Results are stored in result[]; -1 means no greater element exists on the left. */
void findPreviousGreater(int arr[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = -1;                      /* assume no greater element */

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];          /* nearest greater on the left */
                break;
            }
        }
    }
}

int main(void) {
    int n;

    printf("=== Previous Greater Element Finder ===\n\n");

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    int *result = (int *)malloc(n * sizeof(int));
    if (arr == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        free(arr);
        free(result);
        return 1;
    }

    printf("Enter %d integers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            free(result);
            return 1;
        }
    }

    findPreviousGreater(arr, result, n);

    printf("\nOutput: ");
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(", ");
        printf("%d", result[i]);
    }
    printf("\n");

    free(arr);
    free(result);
    return 0;
}