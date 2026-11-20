/*Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
 Print the pivot integer x.
 If no such integer exists, print -1. 
Assume that it is guaranteed that there will be at most one pivot integer for the given input.*/
#include <stdio.h>
#include <math.h>

/* Returns the pivot integer x, or -1 if none exists.
   Condition: 1+2+...+x == x+(x+1)+...+n
   Simplifies to: x*x == n*(n+1)/2  */
int findPivotInteger(int n) {
    long long total = (long long)n * (n + 1) / 2;
    long long x = (long long)(sqrt((double)total) + 0.5);   /* nearest integer root */

    if (x * x == total && x <= n)
        return (int)x;

    return -1;
}

int main(void) {
    int n;

    printf("=== Pivot Integer Finder ===\n\n");

    printf("Enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int pivot = findPivotInteger(n);

    printf("\nOutput: %d\n", pivot);

    if (pivot == -1)
        printf("(No pivot integer exists for n = %d.)\n", n);
    else
        printf("(Sum of 1..%d equals sum of %d..%d.)\n", pivot, pivot, n);

    return 0;
}