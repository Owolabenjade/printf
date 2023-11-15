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
				        int num;

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
																																						                    num = va_arg(args, int);
																																								                    if (num < 0)
																																											                    {
																																														                        buffer[buf_index++] = '-';
																																																	                    count++;
																																																			                        num = -num;
																																																						                }
																																										                    if (num == 0)
																																													                    {
																																																                        buffer[buf_index++] = '0';
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
																																																																				                            buffer[buf_index++] = c;
																																																																							                            count++;
																																																																										                            num %= divisor;
																																																																													                        }
																																																										                }
																																														                    break;
																																																                case 'u':
																																																                    num = va_arg(args, unsigned int);
																																																		                    if (num == 0)
																																																					                    {
																																																								                        buffer[buf_index++] = '0';
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
																																																																												                            buffer[buf_index++] = c;
																																																																															                            count++;
																																																																																		                            num %= divisor;
																																																																																					                        }
																																																																		                }
																																																						                    break;
																																																								                case 'o':
																																																								                    num = va_arg(args, unsigned int);
																																																										                    if (num == 0)
																																																													                    {
																																																																                        buffer[buf_index++] = '0';
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
																																																																																				                        buffer[buf_index++] = c;
																																																																																							                        count++;
																																																																																										                    }
																																																																												                    }
																																																														                    break;
																																																																                case 'x':
																																																																                    num = va_arg(args, unsigned int);
																																																																		                    if (num == 0)
																																																																					                    {
																																																																								                        buffer[buf_index++] = '0';
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
																																																																																												                        buffer[buf_index++] = c;
																																																																																															                        count++;
																																																																																																		                    }
																																																																																				                    }
																																																																						                    break;
																																																																								                case 'X':
																																																																								                    num = va_arg(args, unsigned int);
																																																																										                    if (num == 0)
																																																																													                    {
																																																																																                        buffer[buf_index++] = '0';
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
																																																																																																				                        buffer[buf_index++] = c;
																																																																																																							                        count++;
																																																																																																										                    }
																																																																																												                    }
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

							    return count;
}
