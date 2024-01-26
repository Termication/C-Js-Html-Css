#include <stdio.h>
#include <stdarg.h>

// Function that calculates the average of a variable number of arguments
double average(int num, ...) {
    va_list args;
    va_start(args, num);

    double sum = 0.0;

    for (int i = 0; i < num; i++) {
        sum += va_arg(args, double);
    }

    va_end(args);

    return sum / num;
}

int main() {
    // Calculate the average of three numbers
    double result = average(3, 10.5, 20.0, 30.5);

    // Print the result
    printf("Average: %lf\n", result);

    return 0;
}
