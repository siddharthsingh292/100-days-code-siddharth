#include <stdio.h>
#include <stdlib.h>

/* Returns the maximum sum among all subarrays of size k (sliding window) */
long long maxSubarraySum(int arr[], int n, int k) {
    long long windowSum = 0, maxSum;

    /* Sum of the first window */
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    maxSum = windowSum;

    /* Slide the window: add the new element, remove the oldest one */
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum)
            maxSum = windowSum;
    }
    return maxSum;
}

int main(void) {
    int n, k;

    printf("=== Maximum Sum of Subarray of Size K ===\n\n");

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return 1;
        }
    }

    printf("Enter the value of k (subarray size): ");
    if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
        printf("Invalid k. It must be between 1 and %d.\n", n);
        free(arr);
        return 1;
    }

    long long result = maxSubarraySum(arr, n, k);

    printf("\nOutput: %lld\n", result);

    free(arr);
    return 0;
}