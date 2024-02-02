#include "main.h"

/**
 * display_rot13_conversion - Converts a string to rot13 and prints it.
 * @arguments: Printf arguments.
 * Return: Counter of characters printed.
 */
int display_rot13_conversion(va_list arguments)
{
	int index_alphabet, index_rot13, char_counter = 0;
	int found = 0;
	char *input_string = va_arg(arguments, char*);
	char alphabet[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char rot13[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (input_string == NULL)
		input_string = "(null)";

	for (index_alphabet = 0; input_string[index_alphabet]; index_alphabet++)
	{
		found = 0;
		for (index_rot13 = 0; alphabet[index_rot13] && !found; index_rot13++)
		{
			if (input_string[index_alphabet] == alphabet[index_rot13])
			{
				_putchar(rot13[index_rot13]);
				char_counter++;
				found = 1;
			}
		}
		if (!found)
		{
			_putchar(input_string[index_alphabet]);
			char_counter++;
		}
	}
	return (char_counter);
}
