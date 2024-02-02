#include "main.h"

/**
 * display_string - Prints a string.
 * @arguments: Printf argument.
 * Return: The length of the string.
 */
int display_string(va_list arguments)
{
	char *input_str;
	int index, length;

	input_str = va_arg(arguments, char*);

	if (input_str == NULL)
	{
		input_str = "(null)";
		length = find_string_length(input_str);

		for (index = 0; index < length; index++)
			_putchar(input_str[index]);

		return (length);
	}
	else
	{
		length = find_string_length(input_str);

		for (index = 0; index < length; index++)
			_putchar(input_str[index]);

		return (length);
	}
}
