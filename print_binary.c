#include "main.h"
/**
 * print_binary - Prints an unsigned number in binary
 * @ap: List of arguments
 *
 * Return: Number of characters printed
 */
int print_binary(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	unsigned int m = 2147483648; /* (2 ^ 31) */
	unsigned int a[32];
	int i, sum = 0, count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

