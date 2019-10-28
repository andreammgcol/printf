#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
 * _printf - print anything
 * @format: arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	const char *p;

	va_start(arguments, format);
	int num = 0;

	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			_putchar(*p);
			num++;
			continue;
		}
		switch (*++p)
		{
			case 's':
				fun_string(arguments);
				num++;
				break;
			case 'c':
				fun_character(arguments);
				num++;
				break;
		}

	}
va_end(arguments);
return (num);
}
