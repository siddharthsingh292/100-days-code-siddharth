#include <stdio.h>
#include <stdlib.h>

/* Sliding window maximum using a deque that stores INDICES.
   The deque is kept in decreasing order of values, so the front
   always holds the index of the maximum element of the current window. */
void slidingWindowMax(int arr[], int n, int k) {
    int *deque = (int *)malloc(n * sizeof(int));
    if (deque == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    int front = 0, rear = -1;          /* deque is empty when front > rear */

    for (int i = 0; i < n; i++) {
        /* Remove the index that has slid out of the window */
        if (front <= rear && deque[front] <= i - k)
            front++;

        /* Remove smaller elements from the back, they can never be a maximum */
        while (front <= rear && arr[deque[rear]] <= arr[i])
            rear--;

        deque[++rear] = i;

        /* Window is complete from index k-1 onwards: print its maximum */
        if (i >= k - 1) {
            if (i > k - 1)
                printf(" ");
            printf("%d", arr[deque[front]]);
        }
    }
    printf("\n");
    free(deque);
}

int main(void) {
    int n, k;

    printf("=== Sliding Window Maximum ===\n\n");

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

    printf("Enter the value of k (window size): ");
    if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
        printf("Invalid k. It must be between 1 and %d.\n", n);
        free(arr);
        return 1;
    }

    printf("\nOutput: ");
    slidingWindowMax(arr, n, k);

    free(arr);
    return 0;
}