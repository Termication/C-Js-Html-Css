#include "main.h"

/**
 * display_HEXadecimal - Prints the hexadecimal representation of a number.
 * @args: Arguments containing the decimal number to convert.
 * Return: Number of characters printed.
 */
int display_HEXadecimal(va_list args)
{
	int index;
	int *hexArray;
	int charCounter = 0;
	unsigned int decimalNum = va_arg(args, unsigned int);
	unsigned int temp = decimalNum;

	while (decimalNum / 16 != 0)
	{
		decimalNum /= 16;
		charCounter++;
	}
	charCounter++;
	hexArray = malloc(charCounter * sizeof(int));

	for (index = 0; index < charCounter; index++)
	{
		hexArray[index] = temp % 16;
		temp /= 16;
	}
	for (index = charCounter - 1; index >= 0; index--)
	{
		if (hexArray[index] > 9)
			hexArray[index] = hexArray[index] + 7;
		_putchar(hexArray[index] + '0');
	}
	free(hexArray);
	return (charCounter);
}

