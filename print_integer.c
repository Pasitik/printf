#include "main.h"

/**
 * _printf_int - ...
 *
 * @format: ...
 *
 * Return: void
 */

int _printf_int(const char *format, ...)
{
	va_list args;
	int count = 0;
	int width, precision, flags;
	int printed;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'd':
				case 'i':
					width = 0, precision = -1, flags = 0;
					printed = _print_integer(args, width, precision, flags);

					count += printed;
					break;
			}
		} else
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
