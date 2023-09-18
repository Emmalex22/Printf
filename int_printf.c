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
 * calc - a function that calculates digits of a number
 * @t: number
 * Return: the result
*/
int calc(int t)
{
	int s = 0;

	if (t == 0)
		return (1);
	if (t < 0)
		t = -t;
	while (t != 0)
	{
		s++;
		t /= 10;
	}
	return (s);
}
/**
 * print_number - a function that prints integers
 * @n: the integer
 * Return: nuùber of charactes printed
*/
int print_number(int n)
{
	int num_dig = calc(n);
	int i, count;

	int *p = malloc(num_dig * sizeof(int));

	if (!p)
		return (-1);
	count = 0;
	if (n < 0)
	{
		putchar('-');
		n = -n;
		count++;
	}
	for (i = 0; i < num_dig; i++)
	{
		p[i] = n % 10;
		n /= 10;
	}
	for (i = num_dig - 1; i >= 0; i--)
	{
		putchar('0' + p[i]);
		count++;
	}
	free(p);
	return (count);
}
/**
 * _printf_int - a function that prints integers and handles %d and
 *               %i specifiers
 * @format: format of the string
 * Return: number of characters printed
*/
int _printf_int(const char *format, ...)
{
	int v;
	int count = 0;
	va_list arg_list;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(arg_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				if (*format == 'i' || *format == 'd')
				{
					v = va_arg(arg_list, int);
					count += print_number(v);
				}
				else
				{
					putchar('%');
					putchar(*format);
					count += 2;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arg_list);
	return (count);
}
