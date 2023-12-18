#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Description: Program that prints all possible combinations of two different digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int d, p;

    for (d = '0'; d <= '8'; d++)
    {
        for (p = d + 1; p <= '9'; p++)
        {
            putchar(d);
            putchar(p);

            if (d != '8' || p != '9')
            {
                putchar(',');
                putchar(' ');
            }
        }
    }

    putchar('\n');
    return (0);
}
