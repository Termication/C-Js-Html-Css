#include "main.h"

/********** FOR CHAR **********/
/**
 * print_char - Prints a single character.
 * @types: A variable argument list containing the character to be printed.
 * @buffer: A buffer array to handle the character print.
 * @flags: An integer indicating active printing flags.
 * @width: An integer specifying the width of the printed content.
 * @precision: An integer specifying precision for printing.
 * @size: An integer representing the size specifier.
 * Return: The number of characters printed.
 */
 
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*********** FOR STRING **********/
/**
 * print_string - Prints a string.
 * @types: A variable argument list containing the string to be printed.
 * @buffer: A buffer array to handle the string print.
 * @flags: An integer indicating active printing flags.
 * @width: An integer specifying the width of the printed content.
 * @precision: An integer specifying precision for printing.
 * @size: An integer representing the size specifier.
 * Return: The number of characters printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/********* FOR PERCENTAGE SIGN *********/
/**
 * print_percent - Prints a percentage sign.
 * @types: A variable argument list (unused in this function).
 * @buffer: A buffer array to handle the percent sign print.
 * @flags: An integer indicating active printing flags.
 * @width: An integer specifying the width of the printed content.
 * @precision: An integer specifying precision for printing.
 * @size: An integer representing the size specifier.
 * Return: The number of characters printed.
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/********* FOR INT *********/
/**
 * print_int - Prints an integer.
 * @types: A variable argument list containing the integer to be printed.
 * @buffer: A buffer array to handle the integer print.
 * @flags: An integer indicating active printing flags.
 * @width: An integer specifying the width of the printed content.
 * @precision: An integer specifying precision for printing.
 * @size: An integer representing the size specifier.
 * Return: The number of characters printed.
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	int negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}

	index++;

	return (write_number(negative, index, buffer, flags, width, precision, size));
}

/********* PRINT BINARY *********/
/**
 * print_binary - Prints an unsigned binary number.
 * @types: A variable argument list containing the binary number to be printed.
 * @buffer: A buffer array to handle the binary print.
 * @flags: An integer indicating active printing flags.
 * @width: An integer specifying the width of the printed content.
 * @precision: An integer specifying precision for printing.
 * @size: An integer representing the size specifier.
 * Return: The number of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int number, power, index, sum;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	number = va_arg(types, unsigned int);
	power = 2147483648; /* (2 ^ 31) */
	arr[0] = number / power;
	for (index = 1; index < 32; index++)
	{
		power /= 2;
		arr[index] = (number / power) % 2;
	}
	for (index = 0, sum = 0, count = 0; index < 32; index++)
	{
		sum += arr[index];
		if (sum || index == 31)
		{
			char z = '0' + arr[index];

			write(1, &z, 1);
			count++;
		}
	}
    return (count);
}
