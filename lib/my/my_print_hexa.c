/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_print_hexa
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/myprintf.h"

void my_print_hexa(va_list *list)
{
    unsigned int nb = va_arg(*list, unsigned int);
    char *str = malloc(sizeof(char) * 16);
    char print;

    for (int i = 0; nb != 0; i++) {
        print = nb % 16;
        if (print >= 10) {
            str[i] = print += 87;
        } else if (print < 10) {
            str[i] = print += 48;
        }
        nb /= 16;
    }
    str = my_revstr(str);
    my_putstr(str);
}