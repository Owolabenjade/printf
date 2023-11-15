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
																																																																																								case 'u':
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
																																																																																																								case 'o':
																																																																																																									num = va_arg(args, unsigned int);
																																																																																																													if (num == 0)
																																																																																																																		{
																																																																																																																								write(1, "0", 1);
																																																																																																																													count++;
																																																																																																																																	}
																																																																																																																	else
																																																																																																																						{
																																																																																																																												int octal[32];
																																																																																																																																	int i = 0;

																																																																																																																																						while (num > 0)
																																																																																																																																												{
																																																																																																																																																			octal[i++] = num % 8;
																																																																																																																																																									num /= 8;
																																																																																																																																																														}

																																																																																																																																											while (--i >= 0)
																																																																																																																																																	{
																																																																																																																																																								c = octal[i] + '0';
																																																																																																																																																														write(1, &c, 1);
																																																																																																																																																																				count++;
																																																																																																																																																																									}
																																																																																																																																															}
																																																																																																																					break;
																																																																																																																								case 'x':
																																																																																																																									num = va_arg(args, unsigned int);
																																																																																																																													if (num == 0)
																																																																																																																																		{
																																																																																																																																								write(1, "0", 1);
																																																																																																																																													count++;
																																																																																																																																																	}
																																																																																																																																	else
																																																																																																																																						{
																																																																																																																																												int hex[32];
																																																																																																																																																	int i = 0;

																																																																																																																																																						while (num > 0)
																																																																																																																																																												{
																																																																																																																																																																			hex[i++] = num % 16;
																																																																																																																																																																									num /= 16;
																																																																																																																																																																														}

																																																																																																																																																											while (--i >= 0)
																																																																																																																																																																	{
																																																																																																																																																																								c = (hex[i] < 10) ? hex[i] + '0' : hex[i] - 10 + 'a';
																																																																																																																																																																														write(1, &c, 1);
																																																																																																																																																																																				count++;
																																																																																																																																																																																									}
																																																																																																																																																															}
																																																																																																																																					break;
																																																																																																																																								case 'X':
																																																																																																																																									num = va_arg(args, unsigned int);
																																																																																																																																													if (num == 0)
																																																																																																																																																		{
																																																																																																																																																								write(1, "0", 1);
																																																																																																																																																													count++;
																																																																																																																																																																	}
																																																																																																																																																	else
																																																																																																																																																						{
																																																																																																																																																												int hex[32];
																																																																																																																																																																	int i = 0;

																																																																																																																																																																						while (num > 0)
																																																																																																																																																																												{
																																																																																																																																																																																			hex[i++] = num % 16;
																																																																																																																																																																																									num /= 16;
																																																																																																																																																																																														}

																																																																																																																																																																											while (--i >= 0)
																																																																																																																																																																																	{
																																																																																																																																																																																								c = (hex[i] < 10) ? hex[i] + '0' : hex[i] - 10 + 'A';
																																																																																																																																																																																														write(1, &c, 1);
																																																																																																																																																																																																				count++;
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
