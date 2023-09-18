#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_number(int n);
int _strlen(const char *str);
int _printf_int(const char *format, ...);
int calc(int n);
int *mallc(unsigned int size);

#endif
