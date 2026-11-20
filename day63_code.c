#include <stdio.h>
#include <stdlib.h>

/* Kadane's algorithm: returns the maximum contiguous subarray sum.
   Works for all-negative arrays too (returns the largest element). */
long long kadane(const int arr[], int n) {
    long long maxSoFar = arr[0];
    long long currentMax = arr[0];

    for (int i = 1; i < n; i++) {
        // Either extend the current subarray or start fresh at arr[i]
        currentMax = (arr[i] > currentMax + arr[i]) ? arr[i] : currentMax + arr[i];
        if (currentMax > maxSoFar)
            maxSoFar = currentMax;
    }
    return maxSoFar;
}

int main(void) {
    int n;

    printf("=== Maximum Subarray Sum (Kadane's Algorithm) ===\n\n");
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: please enter a positive integer for the size.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers (separated by spaces or new lines):\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error: invalid input at position %d. Please enter integers only.\n", i + 1);
            free(arr);
            return 1;
        }
    }

    printf("\nMaximum subarray sum: %lld\n", kadane(arr, n));

    free(arr);
    return 0;
}