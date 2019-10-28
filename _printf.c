#include <stdio.h>
#include <stdlib.h>
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
	int num = 0;

	va_start(arguments, format);

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
				if (num != '\0')
				{
				fun_string(arguments);
				num++;
				}
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
