#include "main.h"
/**
 * _printf - a function that chooses the best function to handle diffrent
 *           specifiers
 * @format: format of specifier
 * Return: counts numbers of characters printed
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	va_start(ap, format);

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				if (*format == 'i' || *format == 'd')
				{
					int v = va_arg(ap, int);

					count += print_int(v);
				
				}
				else
				{
					if (*format == 'c')
					{
						char c = va_arg(ap, int);
						count += printf_char(c);
					}
					else
					{
						if (*format == 's')
						{
							count += printf_str(va_arg(ap, char *));
						}
					}
				}
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}

