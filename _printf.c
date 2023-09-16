#include "main.h"
/**
 * _printf - Prints output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the NULL byte).
 */
int _printf(const char *format, ...)
{
	int print_char = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_char++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
			{
				int c = va_arg(arg_list, int);
				write(1, &c, 1);
				print_char++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				print_char++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg_list, char *);
				int str_len = 0;

				while (str && str[str_len] != '\0')
					str_len++;

				if (str)
				{
					write(1, str, str_len);
					print_char += str_len;
				}
				else
				{
					write(1, "(null)", 6);
					print_char += 6;
				}
			}
		}
		format++;
	}
	va_end(arg_list);

	return (print_char);
}
