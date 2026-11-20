#include <stdio.h>
#include <stdlib.h>

/* Fills answer[] so that answer[i] = product of all elements except nums[i].
   Uses prefix and suffix products, with no division. */
void productExceptSelf(int nums[], int answer[], int n) {
    /* Pass 1: answer[i] holds the product of all elements to the LEFT of i */
    answer[0] = 1;
    for (int i = 1; i < n; i++)
        answer[i] = answer[i - 1] * nums[i - 1];

    /* Pass 2: multiply by the product of all elements to the RIGHT of i */
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }
}

int main(void) {
    int n;

    printf("=== Product of Array Except Self ===\n\n");

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *nums = (int *)malloc(n * sizeof(int));
    int *answer = (int *)malloc(n * sizeof(int));
    if (nums == NULL || answer == NULL) {
        printf("Memory allocation failed.\n");
        free(nums);
        free(answer);
        return 1;
    }

    printf("Enter %d integers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(nums);
            free(answer);
            return 1;
        }
    }

    productExceptSelf(nums, answer, n);

    printf("\nOutput: [");
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(",");
        printf("%d", answer[i]);
    }
    printf("]\n");

    free(nums);
    free(answer);
    return 0;
}