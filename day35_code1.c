//Find the second largest element in an array.
#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter the number of elements: ");   // printf: prompt before taking input
    scanf("%d", &n);                            // scanf: reads the size of the array

    int arr[n];

    printf("Enter %d elements: ", n);           // printf: prompt before taking input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);                   // scanf: reads each array element
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("No second largest element\n");  // printf: prints message if no valid second largest
    } else {
        printf("Second largest element: %d\n", second);  // printf: prints the result
    }

    return 0;
}