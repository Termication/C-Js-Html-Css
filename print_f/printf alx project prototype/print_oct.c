#include "main.h"

/**
 * display_octal - Displays an octal number.
 * @args: Arguments containing the decimal number to convert.
 * Return: Number of characters printed.
 */
int display_octal(va_list args)
{
	int index;
	int *octalArray;
	int charCounter = 0;
	unsigned int decimalNum = va_arg(args, unsigned int);
	unsigned int temp = decimalNum;

	while (decimalNum / 8 != 0)
	{
		decimalNum /= 8;
		charCounter++;
	}
	charCounter++;
	octalArray = malloc(charCounter * sizeof(int));

	for (index = 0; index < charCounter; index++)
	{
		octalArray[index] = temp % 8;
		temp /= 8;
	}
	for (index = charCounter - 1; index >= 0; index--)
	{
		_putchar(octalArray[index] + '0');
	}
	free(octalArray);
	return (charCounter);
}
