nclude <limits.h>
#include <stdio.h>
#include "main.h"

/**
 *  * main - Entry point
 *   *
 *    * Return: Always 0
 *     */
int main(void)
{
		int len1, len2;
			unsigned int ui;
				void *addr;

					/* Task 1: Testing handling %c, %s, %% */
					len1 = _printf("Let's try to printf a simple sentence.\n");
						len2 = printf("Let's try to printf a simple sentence.\n");
							_printf("Length:[%d, %i]\n", len1, len1);
								printf("Length:[%d, %i]\n", len2, len2);
									_printf("Negative:[%d]\n", -762534);
										printf("Negative:[%d]\n", -762534);
											_printf("Unsigned:[%u]\n", 2147484671);
												printf("Unsigned:[%u]\n", 2147484671);
													_printf("Character:[%c]\n", 'H');
														printf("Character:[%c]\n", 'H');
															_printf("String:[%s]\n", "I am a string !");
																printf("String:[%s]\n", "I am a string !");
																	_printf("Address:[%p]\n", (void *)0x7ffe637541f0);
																		printf("Address:[%p]\n", (void *)0x7ffe637541f0);
																			len1 = _printf("Percent:[%%]\n");
																				len2 = printf("Percent:[%%]\n");
																					_printf("Len:[%d]\n", len1);
																						printf("Len:[%d]\n", len2);

																							/* Task 2: Testing handling %d, %i */
																							ui = (unsigned int)INT_MAX + 1024;
																								addr = (void *)0x7ffe637541f0;
																									_printf("Unsigned octal:[%o]\n", ui);
																										printf("Unsigned octal:[%o]\n", ui);
																											_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
																												printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
																													len1 = _printf("Unknown:[%r]\n");
																														len2 = printf("Unknown:[%r]\n");

																															return (0);
}
