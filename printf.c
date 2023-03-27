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
	char *arg_str;
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
			arg_str = va_arg(args, char *);
			if (arg_str != NULL)
			{
				len = _strlen(arg_str);

				write(STDOUT_FILENO, arg_str, len);
				(*count) += len;
			}
			break;
		}
		case 'd':
		case 'i':
		{
			_print_integer(va_arg(args, int));
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

