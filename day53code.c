/*Write a Program to take an array of integers as input, calculate the pivot index of this array.
 The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
  If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
  This also applies to the right edge of the array. 
Print the leftmost pivot index. If no such index exists, print -1.*/
#include <stdio.h>
#include <stdlib.h>

/* Returns the leftmost pivot index, or -1 if none exists */
int findPivotIndex(int nums[], int n) {
    long long total = 0, leftSum = 0;

    for (int i = 0; i < n; i++)
        total += nums[i];

    for (int i = 0; i < n; i++) {
        long long rightSum = total - leftSum - nums[i];

        if (leftSum == rightSum)
            return i;                /* first (leftmost) pivot found */

        leftSum += nums[i];
    }
    return -1;
}

int main(void) {
    int n;

    printf("=== Pivot Index Finder ===\n\n");

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(nums);
            return 1;
        }
    }

    int pivot = findPivotIndex(nums, n);

    printf("\nOutput: %d\n", pivot);

    if (pivot == -1)
        printf("(No pivot index exists in the array.)\n");
    else
        printf("(Left sum and right sum are both equal at index %d.)\n", pivot);

    free(nums);
    return 0;
}