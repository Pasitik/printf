#include <stdarg.h>
#include "main.h"
/**
 * _printf - ...
 *
 * @format: ...
 * Return: ...
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;
	va_start(args, fmt);

	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			*(format + i);
			if (*(format + i) == 'c')
			{
				char *c = va_arg(args, char *);
				_putchar(c);
			}
		}

		i++;
	}
	va_end(args);
	return c;

}
