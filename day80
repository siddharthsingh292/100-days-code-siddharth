#include <stdio.h>

int main() {
    FILE *fp;

    char name[50];
    int roll;
    int marks;
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("Error creating file!");
        return 1;
    }

    for (int i = 0; i < n; i++) {

        printf("\nEnter details of Student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", name);

        printf("Roll Number: ");
        scanf("%d", &roll);

        printf("Marks: ");
        scanf("%d", &marks);

        fprintf(fp, "%s %d %d\n", name, roll, marks);
    }

    fclose(fp);

    /* Reading data from file */

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("\nStudent Records:\n");

    while (fscanf(fp, "%s %d %d", name, &roll, &marks) == 3) {

        printf("Name: %s | Roll: %d | Marks: %d\n",
               name, roll, marks);
    }

    fclose(fp);

    return 0;
}
