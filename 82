#include <stdio.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main() {
    enum TrafficLight light;
    int choice;

    printf("0. RED\n1. YELLOW\n2. GREEN\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    light = choice;

    switch (light) {
        case RED:
            printf("Stop");
            break;

        case YELLOW:
            printf("Wait");
            break;

        case GREEN:
            printf("Go");
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
