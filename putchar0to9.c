#include <unistd.h>

int main(void)
{
    char digit;

    for (digit = '0'; digit <= '9'; digit++)
    {
        putchar(digit);
    }

    putchar('\n');

    return 0;
}
