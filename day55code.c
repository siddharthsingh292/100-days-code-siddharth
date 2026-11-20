#include <stdio.h>
#include <stdlib.h>

/* Returns the majority element (appears more than n/2 times), or -1 if none exists.
   Uses the Boyer-Moore Voting Algorithm followed by a verification pass. */
int findMajorityElement(int nums[], int n) {
    int candidate = 0, count = 0;

    /* Phase 1: find a possible candidate */
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    /* Phase 2: verify that the candidate really appears more than n/2 times */
    int occurrences = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate)
            occurrences++;
    }

    if (occurrences > n / 2)
        return candidate;

    return -1;
}

int main(void) {
    int n;

    printf("=== Majority Element Finder ===\n\n");

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

    int result = findMajorityElement(nums, n);

    printf("\nOutput: %d\n", result);

    if (result == -1)
        printf("(No majority element exists in the array.)\n");
    else
        printf("(%d appears more than %d times.)\n", result, n / 2);

    free(nums);
    return 0;
}