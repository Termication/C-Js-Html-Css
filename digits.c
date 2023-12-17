#include <unistd.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Program that prints the digits and lowercase alphabet in order.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int di;

    for (di = '0'; di <= '9' || di <= 'f'; di++)
    {
        putchar(di);
        if (di == '9')  // Add a condition to switch from digits to lowercase letters
        {
            di = 'a' - 1;  // Start with the next character after '9'
        }
    }

    putchar('\n');

    return (0);
}
