#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct print_struct - structure for printing various types
 * @t: type to print
 * @f: function to print
 */

typedef struct print_struct
{
	char *t;
	int (*f)(va_list);
} print_type;


int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list c);
int print_s(va_list s);
#endif
