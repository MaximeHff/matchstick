/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** print
*/

#include "include/matchstick.h"

void print_game(match_t *data)
{
    int height = 0;

    for (; data->map[height]; height++)
        my_printf("%s\n", data->map[height]);
}

void print_space(match_t *data)
{
    int height = 0;
    int pipe = 0;
    int width = 0;

    for (; height < data->lines + 2; height++) {
        for (int width = 0; width < ((data->lines * 2) + 1); width++) {
            if (height >= 1 && height <= data->lines && width >=
            data->lines + pipe && width <= ((data->lines * 2) - 1))
                data->map[height][width] = ' ';
            if (height >= 1 && height <= data->lines && width >= 1
            && width <= ((data->lines * 2) / 2 - pipe))
                data->map[height][width] = ' ';
        }
        width = 0;
        pipe += 1;
    }
}

void print_game_board(char **av, match_t *data)
{
    int height = 0;
    int width = 0;

    data->lines = my_getnbr(av[1], data);
    data->map = malloc(sizeof(char *) * (data->lines + 5));
    for (; height < data->lines + 2; height++) {
        data->map[height] = malloc(sizeof(char) * (data->lines * 2) + 5);
        for (; width < ((data->lines * 2) + 1); width++) {
            if (width == 0 || width == ((data->lines * 2)))
                data->map[height][width] = '*';
            if (height >= 1 && height <= data->lines && width >= 1
            && width <= ((data->lines * 2) - 1))
                data->map[height][width] = '|';
            if (height == 0 || height == data->lines + 1)
                data->map[height][width] = '*';
        }
        data->map[height][width] = '\0';
        width = 0;
    }
    data->map[height] = NULL;
    print_space(data);
}