#include "main.h"

/**
 * display_hexadecimal_number - Displays a hexadecimal number.
 * @decimalNum: Decimal number to convert and display.
 * Return: Counter of characters printed.
 */
int display_hexadecimal_number(unsigned long int decimalNum)
{
    long int index;
	long int *hexArray;
	long int charCounter = 0;
	unsigned long int temp = decimalNum;

	while (decimalNum / 16 != 0)
	{
		decimalNum /= 16;
		charCounter++;
	}
	charCounter++;
	hexArray = malloc(charCounter * sizeof(long int));

	for (index = 0; index < charCounter; index++)
	{
		hexArray[index] = temp % 16;
		temp = temp / 16;
	}
	for (index = charCounter - 1; index >= 0; index--)
	{
		if (hexArray[index] > 9)
			hexArray[index] = hexArray[index] + 39;
		_putchar(hexArray[index] + '0');
	}
	free(hexArray);
	return (charCounter);
}

