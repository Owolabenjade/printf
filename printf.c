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
			        char *str;

				    va_start(args, format);

				        for (ptr = format; *ptr != '\0'; ptr++)
						    {
							            if (buf_index >= 1023)
									            {
											                write(1, buffer, buf_index);
													            count += buf_index;
														                buf_index = 0;
																        }

								            if (*ptr == '%' && *(ptr + 1) == 'S')
										            {
												                ptr++;
														            str = va_arg(args, char *);
															                if (str == NULL)
																		                str = "(null)";
																	            while (*str)
																			                {
																						                if (*str < 32 || *str >= 127)
																									                {
																												                    buffer[buf_index++] = '\\';
																														                        buffer[buf_index++] = 'x';
																																	                    buffer[buf_index++] = (*str / 16 < 10) ? (*str / 16 + '0') : (*str / 16 - 10 + 'A');
																																			                        buffer[buf_index++] = (*str % 16 < 10) ? (*str % 16 + '0') : (*str % 16 - 10 + 'A');
																																						                    count += 4;
																																								                    }
																								                else
																											                {
																														                    buffer[buf_index++] = *str;
																																                        count++;
																																			                }
																										                str++;
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
