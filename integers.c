#include "main.h"

/**
 * _print_integer - prints integer to screen.
 *
 * @n: input
 *
 * Return: Alwqys 0 (Success)
 */

int _print_integer(int n)
{
	int dig = 0;
	int temp, i, count = 0;
	char *p;

	if (n > INT_MAX || n < INT_MIN)
		return (-1);

	if (n < 0)
	{
		n = n * -1;
		write(STDOUT_FILENO, "-", 1);
		count++;
	}
	temp = n;
	while (temp > 0)
	{
		dig++;
		temp = temp / 10;
	}

	if (dig == 0)
	{
		write(STDOUT_FILENO, "0", 1);
		count++;
	}
	p = (char *) malloc(sizeof(char) * dig);
	if (p == NULL)
	{
		return (-1);
	}
	for (i = dig - 1; i >= 0; i--)
	{
		*(p + i) = '0' + n % 10;
		n = n / 10;
	}
	write(STDOUT_FILENO, p, dig);
	count += dig;
	free(p);
	return (0);
}
