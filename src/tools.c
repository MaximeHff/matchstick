/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** tools
*/

#include "include/matchstick.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *remove_backn(char *str)
{
    char *new_str = malloc(sizeof(char) + (my_strlen(str) + 6));
    int i = 0;

    for (; str[i] != '\n'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}

int check_txt(char const *str, match_t *data)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57) {
            my_printf("Error: invalid input (positive number expected)\n");
            data->status = 2;
            return (-1);
        }

}

int my_getnbr(char const *str, match_t *data)
{
    int i = 0;
    long nbr = 0;
    int sign = 1;

    if (check_txt(str, data) == -1)
        return (-666);
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign *= -1;
        }
        i += 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr * 10 + str[i] - 48;
        i += 1;
    }
    nbr *= sign;
    if (nbr < -2147483648 || nbr > 2147483647)
        return (0);
    return ((int)nbr);
}