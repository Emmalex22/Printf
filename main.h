#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
void print_number(int n);
int _strlen(const char *str);
void _printf_int(char *format, ...);

#endif
