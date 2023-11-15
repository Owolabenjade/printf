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
			char buffer[1024];
				int count = 0;
					int buf_index = 0;
						const char *ptr;
							char c;
								char *str;
									void *addr;

										va_start(args, format);

											for (ptr = format; *ptr != '\0'; ptr++)
													{
																if (buf_index >= 1023)
																			{
																							write(1, buffer, buf_index);
																										count += buf_index;
																													buf_index = 0;
																															}

																		if (*ptr == '%')
																					{
																									ptr++;
																												switch (*ptr)
																																{
																																				case 'c':
																																									c = va_arg(args, int);
																																													buffer[buf_index++] = c;
																																																	count++;
																																																					break;
																																																								case 's':
																																																									str = va_arg(args, char *);
																																																													if (str == NULL)
																																																																			str = "(null)";
																																																																	while (*str)
																																																																						{
																																																																												buffer[buf_index++] = *str;
																																																																																	str++;
																																																																																						count++;
																																																																																										}
																																																																					break;
																																																																								case 'd':
																																																																								case 'i':
																																																																									/* Handle as before */
																																																																									break;
																																																																												case 'u':
																																																																													/* Handle as before */
																																																																													break;
																																																																																case 'o':
																																																																																	/* Handle as before */
																																																																																	break;
																																																																																				case 'x':
																																																																																					/* Handle as before */
																																																																																					break;
																																																																																								case 'X':
																																																																																									/* Handle as before */
																																																																																									break;
																																																																																												case 'p':
																																																																																													addr = va_arg(args, void *);
																																																																																																	buffer[buf_index++] = '0';
																																																																																																					buffer[buf_index++] = 'x';
																																																																																																									for (int i = sizeof(void *) * 2 - 1; i >= 0; i--)
																																																																																																														{
																																																																																																																				c = ((uintptr_t)addr >> (i * 4)) & 0xF;
																																																																																																																									buffer[buf_index++] = (c < 10) ? c + '0' : c - 10 + 'a';
																																																																																																																													}
																																																																																																													count += 2 + sizeof(void *) * 2;
																																																																																																																	break;
																																																																																																																				case '%':
																																																																																																																					buffer[buf_index++] = '%';
																																																																																																																									count++;
																																																																																																																													break;
																																																																																																																																default:
																																																																																																																																	buffer[buf_index++] = '%';
																																																																																																																																					buffer[buf_index++] = *ptr;
																																																																																																																																									count += 2;
																																																																																																																																												}
																														}
																				else
																							{
																											buffer[buf_index++] = *ptr;
																														count++;
																																}
																					}

												if (buf_index > 0)
														{
																	write(1, buffer, buf_index);
																			count += buf_index;
																				}

													va_end(args);

														return (count);
}
