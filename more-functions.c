#include "main.h"

/**
 * print_char - ...
 *
 * @args: ...
 * @count: ...
 *
 * Return: ...
 */

void print_char(va_list args, int *count)
{
	char c = (char) va_arg(args, int);

	write(STDOUT_FILENO, &c, 1);
	(*count)++;
}

/**
 * print_string - ...
 *
 * @args: ...
 * @count: ...
 *
 * Return: ...
 */
void print_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);
	int len;

	if (s == NULL)
		return;

	len = _strlen(s);

	write(STDOUT_FILENO, s, len);
	(*count) += len;
}

/**
 * print_percent - ...
 *
 * @count: ...
 *
 * Return: ...
 */
void print_percent(int *count)
{
	char percent = '%';

	write(STDOUT_FILENO, &percent, 1);
	(*count)++;
}

/**
 * print_d - Print decimal integer
 * @args: variable argument list
 * @count: pointer to the total character count
 * Return: void
 */

void print_d(va_list args, int *count)
{
	int width = 0, precision = -1, flags = 0;
	int printed = _print_integer(args, width, precision, flags);

	*count += printed;
}
