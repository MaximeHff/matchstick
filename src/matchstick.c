/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** matchstick
*/

#include "include/matchstick.h"

void init(match_t *data)
{
    data->yours = 0;
    data->status = 0;
    data->pipe_total = 0;
    data->ai_rand = 0;
    data->ai_matches = 0;
    data->debug = 0;
}

int main(int ac, char **av)
{
    match_t *data = malloc(sizeof(match_t));

    usage(ac, av, data);
    if (data->win == -1)
        return (0);
    if (error(ac, av, data) == 84)
        return (84);
    init(data);
    data->nb_rm_max = my_getnbr(av[2], data);
    print_game_board(av, data);
    game(data);
    if (data->win == 1)
        return (1);
    if (data->win == 2)
        return (2);
    return (0);
}