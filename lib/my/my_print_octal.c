/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_print_octal
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/myprintf.h"

void my_print_octal(va_list *list)
{
    unsigned int nb = va_arg(*list, unsigned int);
    char *str = malloc(sizeof(char) * 8);

    for (int i = 0; nb != 0; i++) {
        str[i] = nb % 8 + 48;
        nb /= 8;
    }
    str = my_revstr(str);
    my_putstr(str);
}