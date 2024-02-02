#include "main.h"

/**
 * display_integer - Prints an integer.
 * @args: Argument to print.
 * Return: Number of characters printed.
 */
int display_integer(va_list args)
{
	int input_number = va_arg(args, int);
	int num, last_digit = input_number % 10, digit, exponent = 1;
	int i = 1;

	input_number = input_number / 10;
	num = input_number;

	if (last_digit < 0)
	{
		_putchar('-');
		num = -num;
		input_number = -input_number;
		last_digit = -last_digit;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exponent = exponent * 10;
			num = num / 10;
		}
		num = input_number;
		while (exponent > 0)
		{
			digit = num / exponent;
			_putchar(digit + '0');
			num = num - (digit * exponent);
			exponent = exponent / 10;
			i++;
		}
	}
	_putchar(last_digit + '0');

	return (i);
}

/**
 * display_decimal - Prints a decimal.
 * @args: Argument to print.
 * Return: Number of characters printed.
 */
int display_decimal(va_list args)
{
	int input_number = va_arg(args, int);
	int num, last_digit = input_number % 10, digit;
	int i = 1;
	int exponent = 1;

	input_number = input_number / 10;
	num = input_number;

	if (last_digit < 0)
	{
		_putchar('-');
		num = -num;
		input_number = -input_number;
		last_digit = -last_digit;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exponent = exponent * 10;
			num = num / 10;
		}
		num = input_number;
		while (exponent > 0)
		{
			digit = num / exponent;
			_putchar(digit + '0');
			num = num - (digit * exponent);
			exponent = exponent / 10;
			i++;
		}
	}
	_putchar(last_digit + '0');

	return (i);
}

