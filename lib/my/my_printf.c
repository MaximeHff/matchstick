/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-bsmyprintf-maxime.hoffbeck
** File description:
** my_printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "../../include/myprintf.h"

int find_my_function(char *flags, char my_element)
{
    int my_tab = 0;

    for (; flags[my_tab] != 0; my_tab++) {
        if (flags[my_tab] == my_element)
            return (my_tab);
    }
    return (-1);
}

void my_printf(char *src, ...)
{
    void (*print_function[11])(va_list*) = {my_print_char, my_print_str,
    my_print_nbr, my_print_nbr, my_print_unsigned_nbr, my_print_octal,
    my_print_binary, my_print_octa_str, my_pourcent, my_print_hexa,
    my_print_hexa_maj};
    char flags[12] = {'c', 's', 'd', 'i', 'u', 'o', 'b', 'S', '%', 'x', 'X', 0};
    va_list list;
    int tmpFlags = 0;

    va_start(list, src);
    for (int i = 0; src[i] != 0; i++) {
        if (src[i - 1] == '%' && src[i] != 0) {
            tmpFlags = find_my_function(flags, src[i]);
            if (tmpFlags != -1)
                (*print_function[tmpFlags])(&list);
        } else if (src[i] != '%')
            write(1, &src[i], 1);
    }
    va_end(list);
}