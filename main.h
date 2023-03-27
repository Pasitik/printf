#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

void _putchar(char *c);
char *itoa(int n, int dig);
int num_count(int n);
int _strlen(char *s);
int _print_integer(int n);
void print_arg(char format, va_list args, int *count);
int _printf(const char *format, ...);

#endif /* MAIN_H */
