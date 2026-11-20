/*Arrays (1D)
Find the digit that occurs the most times in an integer number from user input. */
#include <stdio.h>

int main() {
    int number, digit, maxCount = 0, maxDigit = -1;
    int count[10] = {0}; // Array to store count of each digit (0-9)

    printf("Enter an integer: ");
    scanf("%d", &number);

    // Handle negative numbers
    if (number < 0) {
        number = -number;
    }

    // Special case for 0
    if (number == 0) {
        count[0] = 1;
    }

    // Count occurrences of each digit
    while (number > 0) {
        digit = number % 10;
        count[digit]++;
        number /= 10;
    }

    // Find the digit with maximum count
    for (int i = 0; i < 10; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxDigit = i;
        }
    }

    printf("The digit that occurs the most times is: %d\n", maxDigit);
    printf("It occurs %d times.\n", maxCount);

    return 0;
}