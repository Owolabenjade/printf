#include "main.h"
/**
 * hndlePrint - Prints an argument based on its type
 * @fmat: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int hndlePrint(const char *fmat, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unKnwLen = 0, prntdChars = -1;
	fmat_t fmat_types[] = {
		{'c', prntChar}, {'s', printStrng}, {'%', prntPcent},
		{'i', prntInt}, {'d', prntInt}, {'b', prntBnary},
		{'u', prntUnsignd}, {'o', prntOct}, {'x', prntHexD},
		{'X', prntHexUpper}, {'p', prntPointa}, {'S', prntNonPrntable},
		{'r', printRverse}, {'R', prntRot13str}, {'\0', NULL}
	};
	for (i = 0; fmat_types[i].fmat != '\0'; i++)
		if (fmat[*ind] == fmat_types[i].fmat)
			return (fmat_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmat_types[i].fmat == '\0')
	{
		if (fmat[*ind] == '\0')
			return (-1);
		unKnwLen += write(1, "%%", 1);
		if (fmat[*ind - 1] == ' ')
			unKnwLen += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmat[*ind] != ' ' && fmat[*ind] != '%')
				--(*ind);
			if (fmat[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unKnwLen += write(1, &fmat[*ind], 1);
		return (unKnwLen);
	}
	return (prntdChars);
}