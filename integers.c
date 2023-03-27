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
	int sign = 1, i, count = 0;
	char *p;

	if (n < 0)
	{
		sign = -1;
		n = n * -1;
		count++;
	}
	dig += num_count(n);
	if (n == 0)
	{
		p = malloc(2 * sizeof(char));
		if (p == NULL)
			exit(1);
		*(p + 0) = '0';
		*(p + 1) = '\0';
	}
	else
	{
		p = itoa(n, dig);
	}
	if (sign == -1)
		write(STDOUT_FILENO, "-", 1);
	for (i = 0; p[i] != '\0'; i++)
	{
		write(STDOUT_FILENO, &p[i], 1);
		count += 1;
	}
	free(p);
	return (0);
}

/**
 * num_count - ...
 * @n: ...
 * Return: ...
 */
int num_count(int n)
{
	int dig = 0;
	int temp = n;

	while (temp > 0)
	{
		dig++;
		temp = temp / 10;
	}
	return (dig);
}

/**
 * itoa - ...
 * @dig: ...
 * @n: ...
 * Return: ...
 */
char *itoa(int n, int dig)
{
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
