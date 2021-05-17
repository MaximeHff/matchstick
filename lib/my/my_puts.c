/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-maxime.hoffbeck
** File description:
** my_put's
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/myprintf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (0);
}

static int first(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}

char *my_revstr(char *str)
{
    char temp;
    int a = first(str) - 1;

    for (int i = 0; i < a; i++) {
        temp = str[i];
        str[i] = str[a];
        str[a] = temp;
        a--;
    }
    return (str);
}