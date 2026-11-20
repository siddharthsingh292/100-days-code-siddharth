//Write a program to swap the first and last digit of a number.
#include <stdio.h>

int main() {
    int num, firstDigit, lastDigit, swappedNum;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Find the last digit
    lastDigit = num % 10;
    
    // Find the first digit
    while (num >= 10) {
        num /= 10;
    }
    firstDigit = num;
    
    // Swap the digits
    swappedNum = lastDigit * 10 + firstDigit;
    
    printf("Original number: %d\n", firstDigit * 10 + lastDigit);
    printf("Number after swapping first and last digits: %d\n", swappedNum);
    
    return 0;
}