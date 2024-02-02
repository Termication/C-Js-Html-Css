#include "main.h"

/**
 * display_character - Prints a character.
 * @arguments: Printf arguments containing the character to print.
 * Return: The number of characters printed.
 */
int display_character(va_list arguments)
{
	char character;

	character = va_arg(arguments, int);
	_putchar(character);
	return (1);
}

