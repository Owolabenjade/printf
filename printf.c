#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 *  * _printf_task2 - Task 2: Custom printf function handling %d, %i
 *   * @format: Format string
 *    *
 *     * Return: Number of characters printed (excluding null byte)
 *      */
int _printf_task2(const char *format, ...)
{
		va_list args;
			int count = 0;
				const char *ptr;
					char c;
						unsigned int num;

							va_start(args, format);

								for (ptr = format; *ptr != '\0'; ptr++)
										{
													if (*ptr == '%')
																{
																				ptr++;
																							switch (*ptr)
																											{
																															case 'd':
																																			case 'i':
																																				num = va_arg(args, unsigned int);
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
