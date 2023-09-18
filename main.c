#include "main.h"
/**
 * main - mmm
 * Return: 0
*/
int main(void)
{
	int x = 45;
	int z = -4832;
	int y = 488000;

	_printf_int("hello");
	_printf_int("hello %d\n", x);
	_printf_int("hello %d\n", y);
	_printf_int("%!\n");
	_printf_int("%k\n");
        _printf_int("di%ddi%i\n", x, z);
  _printf_int("%");
  _printf_int("%!\n");
  _printf_int("should print single percent sign: %%\n");
  return (0);
}
