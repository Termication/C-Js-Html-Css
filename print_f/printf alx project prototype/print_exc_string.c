#include "main.h"

/**
 * display_special_string - Prints a string with special characters represented in hexadecimal.
 * @arguments: Printf arguments containing the string to print.
 * Return: The number of characters printed.
 */
int display_special_string(va_list arguments)
{
	char *input_str;
	int index, length = 0;
	int char_value;

	input_str = va_arg(arguments, char*);

	if (input_str == NULL)
		input_str = "(null)";

	for (index = 0; input_str[index] != '\0'; index++)
	{
		if (input_str[index] < 32 || input_str[index] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length += 2;
			char_value = input_str[index];

			if (char_value < 16)
			{
				_putchar('0');
				length++;
			}

			length += display_hexadecimal_extra(char_value);
		}
		else
		{
			_putchar(input_str[index]);
			length++;
		}
	}
	return (length);
}

