#include "main.h"
/**
 * _printf - ...
 *
 * @format: ...
 * Return: ...
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			print_arg(*(++format), args, &count);
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

/**
 * print_arg - ...
 *
 * @format: ...
 * @args: ...
 * @count: ...
 * Return: ...
 */
void print_arg(char format, va_list args, int *count)
{
	char arg;
	int len;

	switch (format)
	{
		case 'c':
		{
			arg = (char) va_arg(args, int);
			write(STDOUT_FILENO, &arg, 1);
			(*count)++;
			break;
		}
		case 's':
		{
			arg = *va_arg(args, char *);
			len = _strlen(&arg);

			write(STDOUT_FILENO, &arg, len);
			(*count) += len;
			break;
		}
		case '%':
		{
			arg = '%';
			write(STDOUT_FILENO, &arg, 1);
			(*count)++;
			break;
		}
	}
}

