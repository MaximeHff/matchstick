/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_print_str
*/

#include <stdarg.h>
#include "../../include/myprintf.h"

void my_print_str(va_list *list)
{
    char *src = va_arg(*list, char *);

    for (int a = 0; src[a] != '\0'; a++)
        my_putchar(src[a]);
}