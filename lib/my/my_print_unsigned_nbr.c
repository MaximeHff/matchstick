/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_print_nbr
*/

#include <stdarg.h>
#include "../../include/myprintf.h"

void my_print_unsigned_nbr(va_list *list)
{
    unsigned int nb = va_arg(*list, unsigned int);
    int d = 1;

        if(nb >= 4294967295)
            my_putstr("Your 'unsigned int' is too long");
        else {
            while ((nb / d) >= 10)
                d *= 10;
            while (d > 0) {
                my_putchar((nb / d) % 10 + '0');
                d /= 10;
            }
        }
}