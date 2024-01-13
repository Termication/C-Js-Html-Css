#include <stdio.h>

void swapInCircle(int *a, int *b, int *c, int *d) {
    int temp = *a;
    *a = *d;
    *d = *c;
    *c = *b;
    *b = temp;
}

int main() {
    int num1, num2, num3, num4;

    // Input four numbers
    printf("Enter four numbers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    // Display the original values
    printf("Original values: %d %d %d %d\n", num1, num2, num3, num4);

    // Swap in circular form
    swapInCircle(&num1, &num2, &num3, &num4);

    // Display the swapped values
    printf("Swapped values: %d %d %d %d\n", num1, num2, num3, num4);

    return 0;
}
