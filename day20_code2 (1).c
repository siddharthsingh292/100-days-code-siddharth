//Write a program to find the 1’s complement of a binary number and print it.
#include <stdio.h>
int main() {
    int binary, onesComplement = 0, place = 1, digit;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while (binary != 0) {
        digit = binary % 10;
        if (digit == 0) {
            onesComplement += place; // Change 0 to 1
        }
        // If digit is 1, we do nothing as it remains 0 in one's complement
        binary /= 10;
        place *= 10; // Move to the next place value
    }

    printf("1's complement is %d\n", onesComplement);
    return 0;
}