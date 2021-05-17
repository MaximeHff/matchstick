/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_print_nbr
*/

#include <stdarg.h>
#include "../../include/myprintf.h"

void my_print_nbr(va_list *list)
{
    int nb = va_arg(*list, int);
    int d = 1;

    if(nb < -2147483648 || nb > 2147483648)
        my_putstr("Your 'int' is too long");
    else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        } while ((nb / d) >= 10)
            d *= 10;
        while (d > 0) {
            my_putchar((nb / d) % 10 + '0');
            d /= 10;
        }
    }
}