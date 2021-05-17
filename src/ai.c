/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** ai
*/

#include "include/matchstick.h"

void ai_possibilites2(match_t *data)
{
    if (data->debug > data->lines * 2)
        data->ai_matches = 1;
}

void ai_possibilites(match_t *data)
{
    if (data->nb_rm_max == 2) {
        if (data->pipe_total % 3 == 2)
            data->ai_matches = 2;
        if (data->pipe_total % 3 == 1)
            data->ai_matches = 1;
        else
            data->ai_matches = 1;
        data->debug++;
    }
    if (data->nb_rm_max >= 3) {
        if (data->pipe_total % 4 == 3)
            data->ai_matches = 2;
        if (data->pipe_total % 4 == 2)
            data->ai_matches = 1;
        if (data->pipe_total % 4 == 0)
            data->ai_matches = 3;
        if (data->pipe_total % 4 == 1)
            data->ai_matches = 1;
        data->debug++;
    }
    ai_possibilites2(data);
}

int ai_game(match_t *data)
{
    int check = 0;

    data->ai_rand = (random() % (data->lines) + 1);
    if (data->nb_rm_max == 1)
        data->ai_matches = 1;
    else {
        ai_possibilites(data);
        if (data->ai_matches == 0)
            data->ai_matches = 1;
    }
    check = ai_check(data);
    if (check < data->ai_matches)
        ai_game(data);
    else {
        ai_remove(data);
        data->debug = 0;
    }
}

int ai_check(match_t *data)
{
    int count = 0;

    for (int z = 0; data->map[data->ai_rand][z] != '\0'; z++)
        if (data->map[data->ai_rand][z] == '|')
            count++;
    return (count);
}

int ai_remove(match_t *data)
{
    int z = data->long_of_lines;

    for (; data->map[data->ai_rand][z] != '|'; z--);
    for (int i = 0; i < data->ai_matches; i++) {
        data->map[data->ai_rand][z] = ' ';
        z--;
    }
}