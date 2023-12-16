#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Description: program that prints the lowercase alphabet in reverse
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
        char d;

        for (d = 'z'; d >= 'a'; d--)
        {
        putchar(d);
        }

        putchar('\n');

        return (0);
}
