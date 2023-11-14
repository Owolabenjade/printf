#include <stdio.h>
#include "main.h"

/**
 *main - Entry point for Task 2
 *
 *Return: Always 0
*/
int main(void)
{
	unsigned int ui;
	void *addr;
	int len;

	/* Task 2: Testing handling %d, %i */
	ui = 2147484671;
	addr = (void *)0x7ffe637541f0;
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	len = _printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n", len);

	return (0);
}
