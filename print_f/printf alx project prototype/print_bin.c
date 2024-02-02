#include "main.h"

/**
 * display_binary - Prints a binary number.
 * @arguments: Parameter containing the decimal number to convert.
 * Return: The number of characters printed.
 */
int display_binary(va_list arguments)
{
	int flag = 0;
	int char_count = 0;
	int index, bit;
	unsigned int decimal_num = va_arg(arguments, unsigned int);
	unsigned int mask;

	for (index = 0; index < 32; index++)
	{
		mask = ((1 << (31 - index)) & decimal_num);
		if (mask >> (31 - index))
			flag = 1;
		if (flag)
		{
			bit = mask >> (31 - index);
			_putchar(bit + '0');
			char_count++;
		}
	}
	if (char_count == 0)
	{
		char_count++;
		_putchar('0');
	}
	return (char_count);
}

