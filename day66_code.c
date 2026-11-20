#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 200003   // prime number, larger than 2 * max array size

typedef struct {
    int value;
    int index;
    int used;
} Entry;

int hash(int x) {
    return x % TABLE_SIZE;
}

// Look up a value, return its index or -1 if absent
int find(Entry *table, int value) {
    int h = hash(value);
    while (table[h].used) {
        if (table[h].value == value)
            return table[h].index;
        h = (h + 1) % TABLE_SIZE;
    }
    return -1;
}

void insert(Entry *table, int value, int index) {
    int h = hash(value);
    while (table[h].used)
        h = (h + 1) % TABLE_SIZE;
    table[h].value = value;
    table[h].index = index;
    table[h].used = 1;
}

int main() {
    int n, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter the target: ");
    scanf("%d", &target);

    Entry *table = (Entry *)calloc(TABLE_SIZE, sizeof(Entry));

    int ansI = -1, ansJ = -1;

    for (int i = 0; i < n; i++) {
        if (nums[i] <= target) {
            int need = target - nums[i];
            int j = find(table, need);
            if (j != -1) {
                ansI = j;
                ansJ = i;
                break;
            }
            insert(table, nums[i], i);
        }
    }

    printf("%d %d\n", ansI, ansJ);

    free(nums);
    free(table);
    return 0;
}