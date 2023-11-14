#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 *_printf - Custom printf function
 *@format: Format string
 *
 *Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	char c;
	char *str;
	int num;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						write(1, str, 1);
						str++;
						count++;
					}
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					if (num < 0)
					{
						write(1, "-", 1);
						count++;
						num = -num;
					}
					if (num == 0)
					{
						write(1, "0", 1);
						count++;
					}
					else
					{
						int divisor = 1;
						while (num / divisor != 0)
							divisor *= 10;
						while (divisor > 1)
						{
							divisor /= 10;
							c = (num / divisor) + '0';
							write(1, &c, 1);
							count++;
							num %= divisor;
						}
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, "%", 1);
					write(1, &(*ptr), 1);
					count += 2;
			}
		}
		else
		{
			write(1, &(*ptr), 1);
			count++;
		}
	}

	va_end(args);

	return (count);
}

/**
 * intToBinary - Helper function to convert an integer to binary
 * @num: The integer to be converted
*/
void intToBinary(unsigned int num)
{
	if (num / 2 != 0)
		intToBinary(num / 2);
	char c = (num % 2) + '0';
	write(1, &c, 1);
}

/**
 * countDigits - Helper function to count the number of digits in a number
 * @num: The number
 * @base: The base of the number system
 *
 * Return: Number of digits
*/
int countDigits(unsigned int num, int base)
{
	int count = 0;
	while (num != 0)
	{
		num /= base;
		count++;
	}
	return (count);
}
