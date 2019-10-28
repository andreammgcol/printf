#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * fun_string - print string
 * @arguments: va_list
 * Return: string
 */
int fun_string(va_list arguments)
{
	char *str;

	for (str = va_arg(arguments, char *); *str; str++)
	{
		_putchar(*str);
	}
	return (*str);
}

/**
 * fun_string - print character
 * @arguments: va_list
 * Return: character
 */
int fun_character(va_list arguments)
{
	int x = 0;

	x = va_arg(arguments, int);
	_putchar(x);
	return (x);
}
