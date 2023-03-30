#include "main.h"

/**
 * _print_integer - prints integer to screen.
 *
 * @args: ...
 * @width: ...
 * @precision: ...
 * @flags: ...`
 *
 * Return: Always 0 (Success)
 */

int _print_integer(va_list args, int width,
		int precision, int flags)
{
	int n = va_arg(args, int);
	int sign = 1;

	char buffer[BUFFER_SIZE];
	char *p;

	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}

	p = int_to_string(n, p);
	apply_integer_flags(&p, sign, flags, width, precision);
	write_to_output(p);

	return (p - buffer);
}

/**
 * int_to_string - ..
 * @n: ...
 * @p: ...
 * Return: ...
 */
char *int_to_string(int n, char *p)
{
	int dig = num_count(n);
	int i;
	char *q;

	if (n == 0)
	{
		*(p++) = '0';
		*(p) = '\0'; /* add null terminatorn */
		return (p);
	}

	for (i = dig - 1; i >= 0; i--)
	{
		*(p + i) = '0' + n % 10;
		n = n / 10;
	}
	*(p + dig) = '\0'; /* add null terminator */

	/* Reverse the string */
	q = p;

	while (*q != '\0')
	{
		q--;
	}
	q++;

	while (p < q)
	{
		char temp = *p;
		*p++ = *q;
		*q-- = temp;
	}

	return (p);
}

void apply_integer_flags(char **p, int sign,
		int flags, int width, int precision)
{
	char buffer[BUFFER_SIZE];
	char *q = buffer;
	int len;

	if (sign == -1)
		*(q++) = '-';
	else if (flags & FLAG_PLUS)
		*(q++) = '+';
	else if (flags & FLAG_SPACE)
		*(q++) = ' ';

	len = _strlen(*p);

	if (precision > len)
		pad_left(&q, precision - len, '0');

	if (flags & FLAG_ZERO && precision <= 0 && width > len + sign)
		pad_left(&q, width - len - sign, '0');

	if (width > len + sign)
		pad_left(&q, width - len - sign, ' ');

	*q = '\0';

	write_to_output(buffer);
}

/**
 * write_to_output - ..
 * @p: ...
 *  Return: ...
 */
void write_to_output(char *p)
{
	write(STDOUT_FILENO, p, _strlen(p));
}

/**
 * add_to_output - ..
 * @str: ...
 * @len: ...
 * Return: ...
 */
void add_to_output(char *str, int len)
{
	write(STDOUT_FILENO, str, len);
}
