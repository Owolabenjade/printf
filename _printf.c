#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 *  * _printf - Custom printf function
 *   * @format: Format string
 *    *
 *     * Return: Number of characters printed (excluding null byte)
 *      */
int _printf(const char *format, ...)
{
		va_list args;
			int count = 0;
				const char *ptr;
					char c;
						char *str;

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
