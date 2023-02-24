#include "main.h"

/**
 * print_triangle - draws a straight line in the terminal
 * @size: input size of trianangle
 * Return: always 0
 */

void print_triangle(int size)
{
	int i, j, a, b;
	int n = size;

	if (n > 1)
	{
		for (i = 1; i <= n; i++)
		{
			j = n - i;

			for (a = 1; a <= j; a++)
				_putchar(' ');
			for (b = 1; b <= i; b++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else if (n == 1)
	{
		_putchar('#');
		_putchar('\n');
	}
	else
	{
		_putchar('\n');
	}
}
