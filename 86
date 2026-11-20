#include <stdio.h>

enum Operation {
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};

int main() {
    enum Operation op;
    int choice;
    int a, b;

    printf("1. ADD\n");
    printf("2. SUBTRACT\n");
    printf("3. MULTIPLY\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    op = choice;

    switch (op) {
        case ADD:
            printf("%d", a + b);
            break;

        case SUBTRACT:
            printf("%d", a - b);
            break;

        case MULTIPLY:
            printf("%d", a * b);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
