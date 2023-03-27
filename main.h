#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void _putchar(char *c);
int _strlen(char *s);
void print_arg(char format, va_list args, int *count);
int _printf(const char *format, ...);
#endif /* MAIN_H */
