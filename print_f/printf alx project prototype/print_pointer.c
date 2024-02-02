#include "main.h"

/**
 * display_memory_address - Prints the hexadecimal representation of a memory address.
 * @args: Arguments containing the memory address to print.
 * Return: Number of characters printed.
 */
int display_memory_address(va_list args)
{
	void *memory_address;
	char *placeholder = "(nil)";
	unsigned long int hex_value;
	int character_count;
	int i;

	memory_address = va_arg(args, void*);

	if (memory_address == NULL)
	{
		for (i = 0; placeholder[i] != '\0'; i++)
		{
			_putchar(placeholder[i]);
		}
		return (i);
	}

	hex_value = (unsigned long int)memory_address;
	_putchar('0');
	_putchar('x');
	character_count = display_hexadecimal_number(hex_value);
	return (character_count + 2);
}
