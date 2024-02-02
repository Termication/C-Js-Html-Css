
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#include <limits.h>

#include <unistd.h>

#include <stdlib.h>

#include <stdio.h>



/**
 * struct format - converter for printf
 * @ph: type char pointer of the specifier
 * @function: function for the conversion specifier
 *
 */

typedef struct format
{
	char *specifier;
	int (*function)();
} convert;

int display_percent_char(void);
int display_HEXadecimal(va_list args);
int display_rot13_conversion(va_list arguments);
int display_unsigned_integer(va_list arguments);
int display_memory_address(va_list args);
int display_hexadecimal(va_list arguments);
int display_character(va_list arguments);
int display_special_string(va_list arguments);
int display_binary(va_list arguments);
int display_octal(va_list args);
int display_hexadecimal_extra(unsigned int decimal_num);
int display_decimal(va_list args);
int find_constant_string_length(const char *str);
int find_string_length(char *str);
int display_string(va_list arguments);
int display_integer(va_list args);
int display_hexadecimal_number(unsigned long int decimalNum);
int display_reversed_string(va_list arguments);
int display_character(va_list arguments);
int _putchar(char c);
int _printf(const char *format, ...);

#endif

