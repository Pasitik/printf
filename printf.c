#include "main.h"
/**
 * _printf - ...
 *
 * @format: ...
 * Return: ...
 */

int _printf(const char *format, ...)
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
				case 'c':
					print_char(args, &count);
					break;
				case 's':
					print_string(args, &count);
					break;
				case 'i':
				case 'd':
					width = 0, precision = -1, flags = 0;
					printed = _print_integer(args, width, precision, flags);

					count += printed;
					break;
				case '%':
					{
						print_percent(&count);
						break;
					}
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
