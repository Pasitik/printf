#include "main.h"

/**
 * _printf - ...
 *
 * @format: ...
 * Return: ...
 */
int _printf(const char *format, ...)
{
	int i, len;
	va_list args;

	va_start(args, format);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{

			i++;
			if (*(format + i) == 'c')
			{
				char c = va_arg(args, char *);

				_putchar(c);
			}

			else if (*(format + i) == 's')
			{
				char *s = va_arg(args, char *);

				write(STDOUT_FILENO, s, _strlen(s));
			}

			else
			{
				i--;
				_putchar(*(format + i));
				write(STDOUT_FILENO, *(format + i), 1);
			}
		}
		else
		{
			_putchar(*(format + i));
		}
		i++;
	}
	va_end(args);
	return (0);
}

/**
 * _strlen - ...
 *
 * @s: ...
 * Return: ...
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
