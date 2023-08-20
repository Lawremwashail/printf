#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - format text
 * @format: format specifier
 *
 * Return: number of characters
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			sum++;
		}
		else
		{
			format++;

			if (*format == '\0')
			{
				break;
			}

			if (*format == '%')
			{
				write(1, format, 1);
				sum++;
			}
			else if (*format == 'c')
			{
				char c = (va_arg(list, int));

				write(1, &c, 1);
				sum++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
				{
					str_len++;
				}
				write(1, str, str_len);
				sum += str_len;
			}
		}
		format++;
	}
	va_end(list);
	return (sum);
}
