#include "main.h"

/**
 * display_unsigned_integer - Prints an unsigned integer.
 * @arguments: Printf arguments containing the unsigned integer to print.
 * Return: Number of characters printed.
 */
int display_unsigned_integer(va_list arguments)
{
	unsigned int number = va_arg(arguments, unsigned int);
	int temp, last_digit = number % 10, digit, power = 1;
	int character_count = 1;

	number = number / 10;
	temp = number;

	if (last_digit < 0)
	{
		_putchar('-');
		temp = -temp;
		number = -number;
		last_digit = -last_digit;
		character_count++;
	}

	if (temp > 0)
	{
		while (temp / 10 != 0)
		{
			power = power * 10;
			temp = temp / 10;
		}

		temp = number;

		while (power > 0)
		{
			digit = temp / power;
			_putchar(digit + '0');
			temp = temp - (digit * power);
			power = power / 10;
			character_count++;
		}
	}

	_putchar(last_digit + '0');
	return (character_count);
}
