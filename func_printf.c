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
 * fun_character - print character
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

/**
 * fun_integer - print integer and digit
 * @arguments: va_list
 * Return: int
 */
int fun_integer(va_list arguments)
{
	int i, d, length;
	unsigned int cont;

	i  = va_arg(arguments, int);
	d = 1;
	length = 0;

	if (i < 0)
	{
		length = length + _putchar('-');
		cont = i * -1;
	}
	else
	{
		cont = i;
	}

	while (cont / d > 9)
	d = d * 10;

	while (d != 0)
	{
		length = length + _putchar('0' + cont / d);
		cont = cont % d;
		d = d / 10;
	}
	return (i);
}
