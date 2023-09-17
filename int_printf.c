#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_number - a function that prints integers
 * @n: the integer
*/
void print_number(int n)
{
	if (n >= 10)
		print_number(n / 10);
	_putchar('0' + n % 10);
}
/**
 * _printf_int - a function that prints integers and handles %d and
 *               %i specifiers
 * @format: format of the string
*/
void _printf_int(const char *format, ...)
{
	va_list ap;
	int v;

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'i' || *(format + 1) == 'd'))
		{
			v = va_arg(ap, int);
			if (v < 0)
			{
				_putchar('-');
				v = -v;
			}
			print_number(v);
			format += 2;
		}
	}
	va_end(ap);
}
