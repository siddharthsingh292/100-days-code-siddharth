/* Write a program to print the following pattern:
*****
 ****
  ***
   **
    *
*/
#include <stdio.h>

void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    printPattern(n);
    return 0;
}