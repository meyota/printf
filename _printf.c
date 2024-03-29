#include "main.h"

/**
 * check_specifier - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */

static int (*check_specifier(const char *format))(va_list)
{
	unsigned int i;
	print_type p[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"u", print_u},
		{"S", print_S},
		{"p", print_p},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (i = 0; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
			break;
	}

	return (p[i].f);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(valist, format);

	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}

		if (!format[i])
			return (count);

		f = check_specifier(&format[i + 1]);
		if (f != NULL)
		{
			count += f(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (count);
}
