/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_print_octa_str
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../include/myprintf.h"

static void my_print_octal2(int nb)
{
    char *str = malloc(sizeof(char) * 8);
    int i = 0;

    for (; nb != 0; i++) {
        str[i] = nb % 8 + 48;
        nb /= 8;
    }
    for (; i < 3; i++)
        str[i] = '0';
    str = my_revstr(str);
    my_putstr(str);
}

void my_print_octa_str(va_list *list)
{
    char *value = va_arg(*list, char *);

    for (int a = 0; value[a] != '\0'; a++) {
        if (value[a] >= 32 && value[a] <= 127)
            my_putchar(value[a]);
        else {
            my_putchar('\\');
            my_print_octal2(value[a]);
        }
    }
}