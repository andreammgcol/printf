#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

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
         putchar(*p);
         num++;
         continue;
      }
      switch (*++p)
      {
        case 's':
            for (str = va_arg(arguments, char *); *str; str++)
	    {
                printf("%s", *str);
                num++;
            }
            break;
        case 'c':
            x = va_arg(arguments, int);
            printf("%c", x);
            num++;
            break;
        default:
            putchar(*p);
            num++;
            break;
      }
     
   }
   va_end(arguments);
   
   return (num);
}
