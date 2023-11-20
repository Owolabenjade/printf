#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *print_char - Print a character
 *@c: Character to print
 *Return: Number of characters printed (1)
*/
int print_char(char c)
{
	return write(1, &c, 1);
}

/**
 *print_str - Print a string
 *@str: String to print
 *Return: Number of characters printed
*/
int print_str(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		count += write(1, str, 1);
		str++;
	}

	return (count);
}

/**
 *print_number - Print a number (d or i)
 *@num: Number to print
 *Return: Number of characters printed
*/
int print_number(int num)
{
	int count = 0;

	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += print_char(num % 10 + '0');
	return (count);
}

/**
 *_printf - Custom printf function
 *@format: Format string
 *Return: Number of characters printed
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
					count += print_char(c);
					break;
				case 's':
					str = va_arg(args, char *);
					count += print_str(str);
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					count += print_number(num);
					break;
				case '%':
					count += print_char('%');
					break;
				default:
					count += print_char('%');
					count += print_char(*ptr);
					break;
			}
		}
		else
		{
			count += print_char(*ptr);
		}
	}


	va_end(args);
	return (count);
}
