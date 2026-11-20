/*Arrays (1D)
Count positive, negative, and zero elements in an array.*/  
#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }

    printf("Positive elements: %d\n", positiveCount);
    printf("Negative elements: %d\n", negativeCount);
    printf("Zero elements: %d\n", zeroCount);

    return 0;
}