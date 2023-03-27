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
	va_start(args, format);
	int count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
				{
					char c = (char) va_arg(args, int);
					write(STDOUT_FILENO, &c, 1);
					count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					int len = _strlen(s);
					write(STDOUT_FILENO, s, len);
					count += len;
					break;
				}
				case '%':
				{
					char percent = '%';
					write(STDOUT_FILENO, &percent, 1);
					count++;
					break;
				}
			}
		}
		else 
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * strlen - ...
 *
 * @s: ...
 * Return: ...
 */
int _strlen(char *s){
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
