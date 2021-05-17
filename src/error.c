/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** error
*/

#include "include/matchstick.h"

int usage(int ac, char **av, match_t *data)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("USAGE\n\t./matchstick [number of lines] [maximum number ");
        my_printf("of matches to be removed]\n");
        my_printf("DESCRIPTION\n\tThe goal of this game is to remove a ");
        my_printf("number of matches and play against the AI.\n");
        data->win = -1;
        return (0);
    }
    return (0);
}

int error(int ac, char **av, match_t *data)
{
    if (ac != 3) {
        write(2, "[ERROR] Not enough arguments.\n", 31);
        return (84);
    }
    for (int j = 0; av[1][j]; j++)
        if (av[1][j] < 48 || av[1][j] > 57) {
            write(2, "[ERROR] Enter a number.\n", 25);
            return (84);
        }
    if (my_getnbr(av[1], data) <= 1 || my_getnbr(av[1], data) >= 100) {
        write(2, "[ERROR] Your number of 'lines' is not correct.\n", 48);
        return (84);
    }
    if (my_getnbr(av[2], data) < 1) {
        write(2, "[ERROR] Your number of 'maximum matches ", 41);
        write(2, "to be removed' is too small.\n", 30);
        return (84);
    }
}