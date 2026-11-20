/*Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. 
This element is called the ceil of x. If such an element does not exist, print -1.
 Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.*/
#include <stdio.h>
#include <stdlib.h>

/* Binary search: returns index of the first element >= x, or -1 if none exists */
int findCeilIndex(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            result = mid;        /* possible answer, try to find an earlier one */
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main(void) {
    int n, x;

    printf("=== Ceil Index Finder ===\n\n");

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

    printf("Enter %d elements in SORTED (ascending) order, separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return 1;
        }
    }

    /* Check that the array is actually sorted */
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            printf("Error: the array is not sorted in ascending order.\n");
            free(arr);
            return 1;
        }
    }

    printf("Enter the value of x: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        free(arr);
        return 1;
    }

    int index = findCeilIndex(arr, n, x);

    printf("\nOutput: %d\n", index);

    if (index == -1)
        printf("(No element greater than or equal to %d exists in the array.)\n", x);
    else
        printf("(Ceil of %d is %d, found at index %d.)\n", x, arr[index], index);

    free(arr);
    return 0;
}