#include <unistd.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Program that prints the lowercase alphabet in reverse.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char d;
    int di;

    for (di = '0'; di <= '9'; di++)
    {
    putchar(di);
    }
    for (d = 'a'; d <= 'f'; d++)
    {
           putchar(d);
    }

    putchar('\n');

    return (0);
}