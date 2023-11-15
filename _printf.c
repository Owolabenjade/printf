#include "main.h"

void prntBuf(char buffer[], int *bufIndx);

/**
 * _printf - Printf funct
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printd = 0, prntdChars = 0;
	int flags, width, precision, size, bufIndx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bufIndx++] = format[i];
			if (bufIndx == BUFF_SIZE)
				prntBuf(buffer, &bufIndx);
			prntdChars++;
		}
		else
		{
			prntBuf(buffer, &bufIndx);
			flags = getFlags(format, &i);
			width = getWidth(format, &i, list);
			precision = getPrecision(format, &i, list);
			size = getSize(format, &i);
			++i;
			printd = hndlePrint(format, &i, list, buffer,
				flags, width, precision, size);
			if (printd == -1)
				return (-1);
			prntdChars += printd;
		}
	}

	prntBuf(buffer, &bufIndx);

	va_end(list);

	return (prntdChars);
}

/**
 * prntBuf - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @bufIndx: Index at which to add next char, represents the length.
 */
void prntBuf(char buffer[], int *bufIndx)
{
	if (*bufIndx > 0)
		write(1, &buffer[0], *bufIndx);

	*bufIndx = 0;
}