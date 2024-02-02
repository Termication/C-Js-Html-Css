#include "main.h"

/**
 * find_string_length - Finds the length of a string.
 * @str: The string to measure.
 * Return: The length of the string.
 */
int find_string_length(char *str)
{
	int count;

	for (count = 0; str[count] != '\0'; count++)
		;
	return (count);
}

/**
 * find_constant_string_length - Finds the length of a constant string.
 * @str: The constant string to measure.
 * Return: The length of the constant string.
 */
int find_constant_string_length(const char *str)
{
	int count;

	for (count = 0; str[count] != '\0'; count++)
		;
	return (count);
}

