#include "main.h"

/**
 * _print_integer - prints integer to screen.
 *
 * @args: ...
 * @width: ...
 * @precision: ...
 * @flags: ...
 * @length: ...
 *
 * Return: Always 0 (Success)
 */

int _print_integer(va_list args, int width,
		int precision, int flags)
{
	int n = va_arg(args, int);
	int sign = 1;
	char *p;

	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}

	p = int_to_string(n);
	apply_integer_flags(&p, sign, flags, width, precision);
	write_to_output(p);
	free(p);

	return (_strlen(p));
}

/**
 * int_to_string - ..
 * @n: ...
 * Return: ...
 */
char *int_to_string(int n)
{
	int dig = num_count(n);
	int i;
	char *p = (char *) malloc(sizeof(char) * (dig + 1));

	if (p == NULL)
	{
		exit(1);
	}

	for (i = dig - 1; i >= 0; i--)
	{
		*(p + i) = '0' + n % 10;
		n = n / 10;
	}
	*(p + dig) = '\0';

	return (p);
}

void apply_integer_flags(char **p, int sign,
		int flags, int width, int precision)
{
	int len = 0;

	if (sign == -1)
		add_to_output("-", 1);
	else if (flags & FLAG_PLUS)
		add_to_output("+", 1);
	else if (flags & FLAG_SPACE)
		add_to_output(" ", 1);

	len = _strlen(*p);

	if (precision > len)
		pad_left(p, precision - len, '0');

	if (flags & FLAG_ZERO && precision <= 0 && width > len + sign)
		pad_left(p, width - len - sign, '0');

	if (width > len + sign)
		pad_left(p, width - len - sign, ' ');
}

/**
 * write_to_output - ..
 * @p: ...
 *  Return: ...
 */
void write_to_output(char *p)
{
	add_to_output(p, _strlen(p));
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
