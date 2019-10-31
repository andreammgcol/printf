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

	if (format == NULL || *format == '%')
		return (-1);
	va_start(arguments, format);
	for (p = format; *p; p++)
	{
		if (*p == '%' && *p + 1 == '\0')
			return (-1);
		if (*p == '%' && *p + 1 == '%')
		{
			_putchar(*p), num++;
			continue;
		}
		else if (*p == '%' && *p + 1 != '%')
		{
			switch (*++p)
			{
				case 's':
					num += fun_string(arguments);
					break;
				case 'c':
					num += fun_character(arguments);
					break;
				case '%':
					putchar('%'), num++;
					break;
				case 'i':
				case 'd':
					fun_integer(arguments), num++;
					break;
				default:
					putchar('%');
					_putchar(*p), num += 2;
					break;
			}
		}
		else
			_putchar(*p), num++;
	}
va_end(arguments);
return (num);
}

