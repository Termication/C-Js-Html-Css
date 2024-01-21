#include <stdio.h>

// Define an enumeration named 'Color'
enum Color {
    RED,
    GREEN,
    BLUE
};

int main() {
    // Declare a variable of type 'Color'
    enum Color myColor;

    // Assign a value to the 'myColor' variable
    myColor = GREEN;

    // Use the enum values in a switch statement
    switch (myColor) {
        case RED:
            printf("The color is Red.\n");
            break;
        case GREEN:
            printf("The color is Green.\n");
            break;
        case BLUE:
            printf("The color is Blue.\n");
            break;
        default:
            printf("Unknown color.\n");
    }

    return 0;
}
