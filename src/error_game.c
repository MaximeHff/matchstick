/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** error_game
*/

#include "include/matchstick.h"

int error_player(match_t *data, char *line, char *matches)
{
    if (my_getnbr(matches, data) > data->nb_rm_max) {
        my_printf("Error: you cannot remove more than %d matches per turn\n"
        , data->nb_rm_max);
        data->status = 2;
        return (-1);
    }
    if (search_pipe_in_line(data, my_getnbr(line, data),
    my_getnbr(matches, data)) == -1) {
        my_printf("Error: not enough matches on this line\n");
        data->status = 2;
        return (-1);
    }
    if (search_pipe_in_line(data, my_getnbr(line, data),
    my_getnbr(matches, data)) != -1)
        my_printf("Player removed %s match(es) from line %s\n", matches, line);
    data->status = 2;
    return (0);
}

int error_line(match_t *data, char *line)
{
    if (my_getnbr(line, data) == -666)
        return (-1);
    if (my_getnbr(line, data) > data->lines || my_getnbr(line, data) <= 0) {
        my_printf("Error: this line is out of range\n");
        data->status = 2;
        return (-1);
    }
    return (0);
}

int error_matches(match_t *data, char *matches)
{
    if (my_getnbr(matches, data) == -666)
        return (-1);
    if (my_getnbr(matches, data) <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        data->status = 2;
        return (-1);
    }
}