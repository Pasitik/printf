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
					print_d(args, &count);
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
