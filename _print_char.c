#include "main.h"
/**
 * printf_char - a function that prints a character
 * @c: the character
 * Return: 1
*/
int printf_char(char c)
{
	_putchar(c);
	return (1);
}
/**
 * printf_str - a function that prints a string
 * @str: string
 * Return: number of characters printed
*/
int printf_str(char *str)
{
	int str_len = 0;
	int print_char = 0;
	int i;

	while (str && str[str_len] != '\0')
		str_len++;
	if (str)
	{
		for (i = 0; i < str_len; i++)
		{
			_putchar(str[i]);
			print_char++;
		}
	}
	else
	{
		const char *nul_str = "(null)";
		for (i = 0; i < 6; i++)
		{
			_putchar(nul_str[i]);
			print_char++;
		}
	}
	return (print_char);
}

