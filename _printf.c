#include "main.h"
/**
 * _strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *str);
{
    int length = 0;

    while (str && str[length])
        length++;

    return length;
}

/**
 * _printf - Prints output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the NULL byte).
 */
int _printf(const char *format, ...);
{
    if (!format)
        return (-1);

    int print_char = 0;
    va_list arg_list;

    va_start(arg_list, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            print_char++;
        }
        else if (*(++format) == '\0')
            break;
        else if (*format == 'c')
        {
            int c = va_arg(arg_list, int);
            write(1, &c, 1);
            print_char++;
        }
        else if (*format == '%')
        {
            write(1, "%", 1);
            print_char++;
        }
        else if (*format == 's')
        {
            char *str = va_arg(arg_list, char *);
            int str_len = _strlen(str);

            write(1, str ? str : "(null)", str_len);
            print_char += str_len;
        }
        format++;
    }
    va_end(arg_list);

    return (print_char);
}

