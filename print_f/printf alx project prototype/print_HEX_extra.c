#include "main.h"

/**
 * display_hexadecimal_extra - Prints an extra hexadecimal number.
 * @decimal_num: Decimal number to convert and display.
 * Return: Number of characters printed.
 */
int display_hexadecimal_extra(unsigned int decimal_num)
{
	int index;
	int *hex_array;
	int char_counter = 0;
	unsigned int temp = decimal_num;

	while (decimal_num / 16 != 0)
	{
		decimal_num /= 16;
		char_counter++;
	}
	char_counter++;
	hex_array = malloc(char_counter * sizeof(int));

	for (index = 0; index < char_counter; index++)
	{
		hex_array[index] = temp % 16;
		temp /= 16;
	}
	for (index = char_counter - 1; index >= 0; index--)
	{
		if (hex_array[index] > 9)
			hex_array[index] = hex_array[index] + 7;
		_putchar(hex_array[index] + '0');
	}
	free(hex_array);
	return (char_counter);
}

