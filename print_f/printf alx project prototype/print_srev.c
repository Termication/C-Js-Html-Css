#include "main.h"

/**
 * display_reversed_string - Prints a string in reverse order.
 * @arguments: Printf arguments containing the string to reverse.
 * Return: Number of characters printed.
 */
int display_reversed_string(va_list arguments)
{
	char *input_string = va_arg(arguments, char*);
	int index_forward, index_reverse = 0;

	if (input_string == NULL)
		input_string = "(null)";

	while (input_string[index_reverse] != '\0')
		index_reverse++;

	for (index_forward = index_reverse - 1; index_forward >= 0; index_forward--)
		_putchar(input_string[index_forward]);

	return (index_reverse);
}

