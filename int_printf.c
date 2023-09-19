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
 * print_int - a function that prints integers
 * @n: the integer
 * Return: nuùber of charactes printed
*/
int print_int(int n)
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
