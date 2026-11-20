#include <stdio.h>
#include <stdlib.h>

void mergeSortedArrays(int *a, int m, int *b, int n, int *result) {
    int i = 0, j = 0, k = 0;

    // Pick the smaller front element from either array
    while (i < m && j < n) {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    // Copy whatever is left in a
    while (i < m)
        result[k++] = a[i++];

    // Copy whatever is left in b
    while (j < n)
        result[k++] = b[j++];
}

int main() {
    int m, n;

    printf("Enter size of first array: ");
    scanf("%d", &m);
    int *nums1 = (int *)malloc(m * sizeof(int));
    printf("Enter %d sorted elements: ", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &nums1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n);
    int *nums2 = (int *)malloc(n * sizeof(int));
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums2[i]);

    int *result = (int *)malloc((m + n) * sizeof(int));
    mergeSortedArrays(nums1, m, nums2, n, result);

    for (int i = 0; i < m + n; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(nums1);
    free(nums2);
    free(result);
    return 0;
}