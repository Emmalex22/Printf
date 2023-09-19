#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(const char *str);
int print_int(int n);
int calc(int n);
<<<<<<< HEAD
int printf_str(char *str);
int printf_char(char c);
=======
int print_binary(va_list ap);
>>>>>>> 19ba0b4f496d6374c957aa14d0723b81f6de3849

#endif
