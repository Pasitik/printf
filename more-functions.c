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
	int len = _strlen(s);

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
