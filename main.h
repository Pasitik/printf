#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <unistd.h>

#define FLAG_PLUS 1
#define FLAG_MINUS 2
#define FLAG_ZERO 4
#define FLAG_SPACE 8

#define BUFFER_SIZE 1024

int _strlen(char *s);
void _memcpy(char *dest, const char *src, size_t len);
void _memset(char *str, char pad, size_t width);
int _print_integer(va_list args, int width, int precision, int flags);
int _printf(const char *format, ...);
void pad_left(char **str, int width, char pad);
int num_count(int n);
void print_percent(int *count);
void print_char(va_list args, int *count);
void print_string(va_list args, int *counto);
char *int_to_string(int n, char *p);
void apply_integer_flags(char **p, int sign, int flags,
		int width, int precision);
void write_to_output(char *p);
void add_to_output(char *str, int len);
void pad_left(char **p, int count, char c);
void print_d(va_list args, int *count);

#endif /* MAIN_H */
