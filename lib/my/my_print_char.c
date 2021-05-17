/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_print_char
*/

#include <stdarg.h>
#include <unistd.h>
#include "../../include/myprintf.h"

void my_print_char(va_list *list)
{
    char src = va_arg(*list, int);

    write(1, &src, 1);
}