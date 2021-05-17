/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-bsmyprintf-maxime.hoffbeck
** File description:
** bsprintf
*/

#include <stdarg.h>

#ifndef BSPRINTF_H_
#define BSPRINTF_H_

void my_print_char(va_list *list);
void my_print_str(va_list *list);
void my_print_nbr(va_list *list);
void my_print_unsigned_nbr(va_list *list);
void my_print_octal(va_list *list);
void my_print_binary(va_list *list);
void my_print_octa_str(va_list *list);
void my_print_hexa(va_list *list);
void my_print_hexa_maj(va_list *list);
void my_pourcent(va_list *list);
void my_printf(char *src, ...);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);

#endif /* !BSPRINTF_H_ */
