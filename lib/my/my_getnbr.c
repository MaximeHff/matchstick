/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-maxime.hoffbeck
** File description:
** my_get_nbr
*/

int my_getnbr(char const *str)
{
    int s = 1;
    int r = 0;

    while (*str == '-' || *str == '+' || *str == '*'
    || *str == '/' || *str == '%') {
        if (*str == '-')
            s *= -1;
        str += 1;
    }
    while (*str >= '0' && *str <= '9') {
        r = r * 10;
        r = r + *str - 48;
        str += 1;
    }
    r *= s;
    return (r);
}