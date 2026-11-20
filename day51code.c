/*Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs.
 The elements in the sorted array might be repeated. 
 You need to print the first and last occurrence of the target and print the index of first and last occurrence. 
 Print -1, -1 if the target is not present.*/
#include <stdio.h>
#include <stdlib.h>

/* Binary search for the first (findFirst = 1) or last (findFirst = 0) occurrence */
int findPosition(int nums[], int n, int target, int findFirst) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            result = mid;                 /* record the match */
            if (findFirst)
                high = mid - 1;           /* keep searching left */
            else
                low = mid + 1;            /* keep searching right */
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main(void) {
    int n, target;

    printf("=== First and Last Occurrence Finder ===\n\n");

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

    printf("Enter %d elements in SORTED (ascending) order, separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(nums);
            return 1;
        }
    }

    /* Check that the array is actually sorted */
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            printf("Error: the array is not sorted in ascending order.\n");
            free(nums);
            return 1;
        }
    }

    printf("Enter the target value to search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target. Please enter an integer.\n");
        free(nums);
        return 1;
    }

    int first = findPosition(nums, n, target, 1);
    int last  = (first == -1) ? -1 : findPosition(nums, n, target, 0);

    printf("\nOutput: %d,%d\n", first, last);

    if (first == -1)
        printf("(Target %d is not present in the array.)\n", target);

    free(nums);
    return 0;
}