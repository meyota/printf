#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
int (*pfunc)(va_list, flags_t *);
const char *p;
va_list ap;
flags_t flags = {0, 0, 0};
int sum = 0;

va_start(ap, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
sum += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
pfunc = get_print(*p);
sum += (pfunc)
? pfunc(ap, &flags)
:_printf("%%%c", *p);
}
else
sum += _putchar(*p);
}
_putchar(-1);
va_end(ap);
return (sum);
}
