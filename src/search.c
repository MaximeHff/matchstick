/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** search
*/

#include "include/matchstick.h"

int search_pipe_in_line(match_t *data, int line, int matches)
{
    int count = 0;

    for (int z = 0; data->map[line][z] != '\0'; z++)
        if (data->map[line][z] == '|')
            count++;
    if (count < matches)
        return (-1);
    return (count);
}

int replace(match_t *data, int line, int matches)
{
    int z = data->long_of_lines;

    for (; data->map[line][z] != '|'; z--);
    for (int i = 0; i < matches; i++) {
        data->map[line][z] = ' ';
        z--;
    }
}

int search_pipe_total(match_t *data)
{
    int height = 0;
    int width = 0;

    data->pipe_total = 0;
    for (; height < data->lines + 2; height++) {
        for (; width < ((data->lines * 2) + 1); width++) {
            if (data->map[height][width] == '|')
                data->pipe_total++;
        }
        width = 0;
    }
}