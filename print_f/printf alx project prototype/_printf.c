#include "main.h"

/**
 * _printf - A function that formats and prints data based on the format.
 * @format: The format specifier string.
 * Return: The length of the printed string.
 */
int _printf(const char * const format, ...)
{
	convert conversion_specifiers[] = {
		{"%s", display_string}, {"%c", display_character},
		{"%%", display_percent_char},
		{"%i", display_integer}, {"%d", display_decimal}, {"%r", display_reversed_string},
		{"%R", display_rot13_conversion}, {"%b", display_binary},
		{"%u", display_unsigned_integer},
		{"%o", display_octal}, {"%x", display_hexadecimal}, {"%X", display_HEXadecimal},
		{"%S", display_special_string}, {"%p", display_memory_address}
	};

	va_list arguments;
	int index = 0, sub_index, total_length = 0;

	va_start(arguments, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[index] != '\0')
	{
		sub_index = 13;
		while (sub_index >= 0)
		{
			if (conversion_specifiers[sub_index].specifier[0] == format[index] &&
				conversion_specifiers[sub_index].specifier[1] == format[index + 1])
			{
				total_length += conversion_specifiers[sub_index].function(arguments);
				index = index + 2;
				goto ContinuePrint;
			}
			sub_index--;
		}
		_putchar(format[index]);
		total_length++;
		index++;

ContinuePrint:
		continue;
	}
	va_end(arguments);
	return (total_length);
}

