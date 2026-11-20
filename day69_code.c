#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int used;
} Entry;

int findDuplicate(int *nums, int n) {
    int size = 2 * n + 1;                       // table is at least twice the number of elements
    Entry *table = (Entry *)calloc(size, sizeof(Entry));
    int result = -1;

    for (int i = 0; i < n; i++) {
        int h = ((nums[i] % size) + size) % size;   // safe for negative values too

        // Probe until we find the value or an empty slot
        while (table[h].used) {
            if (table[h].value == nums[i]) {
                result = nums[i];                // seen before, this is the repeat
                free(table);
                return result;
            }
            h = (h + 1) % size;
        }

        table[h].value = nums[i];
        table[h].used = 1;
    }

    free(table);
    return result;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("%d\n", findDuplicate(nums, n));

    free(nums);
    return 0;
}