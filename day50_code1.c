//Change the date format from dd/04/yyyy to dd-Apr-yyyy.
#include <stdio.h>
#include <string.h>

#define MAX 100

int isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int m, int y) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y))
        return 29;
    return days[m - 1];
}

int main() {
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char input[MAX];
    char choice;

    printf("=====================================\n");
    printf("      DATE FORMAT CONVERTER\n");
    printf("   dd/mm/yyyy  -->  dd-Mon-yyyy\n");
    printf("=====================================\n");

    do {
        int d, m, y;
        char extra;

        printf("\nEnter date (dd/mm/yyyy): ");
        fgets(input, MAX, stdin);
        input[strcspn(input, "\n")] = '\0';   // remove newline

        // Must match exactly dd/mm/yyyy with nothing extra after it
        if (sscanf(input, "%d/%d/%d %c", &d, &m, &y, &extra) != 3) {
            printf("\nError: Invalid format. Use dd/mm/yyyy (e.g., 15/04/2025).\n");
        } else if (y < 1 || m < 1 || m > 12) {
            printf("\nError: Invalid month or year.\n");
        } else if (d < 1 || d > daysInMonth(m, y)) {
            printf("\nError: Invalid day for the given month.\n");
        } else {
            printf("\nConverted date: %02d-%s-%04d\n", d, months[m - 1], y);
        }

        printf("\nDo you want to convert another date? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Date Converter. Goodbye!\n");
    return 0;
}