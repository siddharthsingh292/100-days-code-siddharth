#include <stdio.h>

void firstNegativeInWindow(int arr[], int n, int k) {
    int queue[n];          // stores indices of negative numbers
    int front = 0, rear = 0;

    // Process the first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            queue[rear++] = i;
        }
    }

    // Answer for the first window
    if (front < rear)
        printf("%d ", arr[queue[front]]);
    else
        printf("0 ");

    // Process remaining windows
    for (int i = k; i < n; i++) {
        // Remove indices that are outside the current window
        while (front < rear && queue[front] <= i - k) {
            front++;
        }

        // Add the new element if it is negative
        if (arr[i] < 0) {
            queue[rear++] = i;
        }

        // Print the answer for this window
        if (front < rear)
            printf("%d ", arr[queue[front]]);
        else
            printf("0 ");
    }
    printf("\n");
}

int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter window size k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid window size\n");
        return 1;
    }

    firstNegativeInWindow(arr, n, k);
    return 0;
}