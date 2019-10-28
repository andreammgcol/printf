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
	char *str;
	int x;

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
				for (str = va_arg(arguments, char *); *str; str++)
				{
					_putchar(*str);
					num++;
				}
				break;
			case 'c':
				x = va_arg(arguments, int);
				_putchar(x);
				num++;
				break;
			default:
				_putchar(*p);
				num++;
				break;
		}

	}
va_end(arguments);
return (num);
}
