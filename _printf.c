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

	if (format == NULL)
		return (-1);
	va_start(arguments, format);
	for (p = format; *p; p++)
	{
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
					_putchar('%'), num++;
					break;
				case '\0':
					return (-1);
				case 'i':
				case 'd':
					num += fun_integer(arguments);
					break;
				default:
					_putchar('%'), _putchar(*p), num += 2;
			}
		}
		else
			_putchar(*p), num++;
	}
va_end(arguments);
return (num);
}
