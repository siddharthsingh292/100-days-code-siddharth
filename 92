#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student s[5];

    for (int i = 0; i < 5; i++) {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll_no);

        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }

    printf("\nStudent Details\n");
    printf("Name\tRoll\tMarks\n");

    for (int i = 0; i < 5; i++) {
        printf("%s\t%d\t%d\n",
               s[i].name,
               s[i].roll_no,
               s[i].marks);
    }

    return 0;
}
