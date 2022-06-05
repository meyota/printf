#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/* print_nums */
int print_unsigned(va_list 1, flags_t *f);
int print_int(va_list 1, flags_t *f);
int count_digit(int i);
void print_number(int n);

/* print bases */
int print_hex(va_list 1, flags_t *f);
int print_hex_big(va_list 1, flags_t *f);
int print_binary(va_list 1, flags_t *f);
int print_octal(va_list 1, flags_t *f);

/* _printf */
int _printf(const char *format, ...);

/* get_flag */
int get_flag(char s, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* print address */
int print_address(va_list 1, flags_t *f);

/* print_percent */
int print_percent(va_list 1, flags_t *f);

/* print_alpha */
int print_char(va_list 1, flags_t *f);
int print_string(va_list 1, flags_t *f);

/* func */
int _putchar(char c);
int _puts(char *str);

#endif
