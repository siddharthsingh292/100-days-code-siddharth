#include <stdio.h>
#include <stdlib.h>

int missingNumber(int *nums, int n) {
    // The array holds n numbers taken from 0..n, so the full range has n + 1 numbers
    long long expected = (long long)n * (n + 1) / 2;
    long long actual = 0;

    for (int i = 0; i < n; i++)
        actual += nums[i];

    return (int)(expected - actual);
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("%d\n", missingNumber(nums, n));

    free(nums);
    return 0;
}