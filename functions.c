#include "main.h"

/**
 * pad_left - ...
 *
 * @str: ...
 * @width: ...
 * @pad: ...
 *
 * Return: ...
 */

void pad_left(char **str, int width, char pad)
{
	char buffer[BUFFER_SIZE];
	char *p = buffer;

	int len = *str - buffer;

	_memset(p, pad, width);
	_memcpy(p + width, *str, len + 1);
	*str = p + width + len;
}

/**
 * _memset - ...
 *
 * @str: ...
 * @width: ...
 * @pad: ...
 *
 * Return: ...
 */
void _memset(char *str, char pad, size_t width)
{
	size_t i;

	for (i = 0; i < width; i++)
	{
		str[i] = pad;
	}
}

/**
 * _memcpy - ...
 *
 * @dest: ...
 * @src: ...
 * @len: ...
 *
 * Return: ...
 */
void _memcpy(char *dest, const char *src, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[len] = '\0';
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
 * _strlen - ...
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
