#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void _putchar(char *c);
int _strlen(char *s);
int _print_integer(int n);
void print_arg(char format, va_list args, int *count);
int _printf(const char *format, ...);

#endif /* MAIN_H */
