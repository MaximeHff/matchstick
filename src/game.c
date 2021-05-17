/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** game
*/

#include "include/matchstick.h"

int perso_turn(match_t *data)
{
    if (data->pipe_total == 0) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        data->win = 1;
        return (1);
    }
    if (data->yours == 0 && data->status == 0)
        my_printf("\nYour turn:\n");
    data->yours = 1;
    my_printf("Line: ");
    if (your_turn(data) == -1) {
        data->win = -1;
        return (1);
    }
}

int your_turn(match_t *data)
{
    size_t buffsize = 4096;
    char *line = malloc(sizeof(char) * buffsize);
    char *matches = malloc(sizeof(char) * buffsize);

    if (getline(&line, &buffsize, stdin) == -1)
        return (-1);
    line = remove_backn(line);
    if (error_line(data, line) == -1)
        return (0);
    my_printf("Matches: ");
    if (getline(&matches, &buffsize, stdin) == -1)
        return (-1);
    matches = remove_backn(matches);
    if (error_matches(data, matches) == -1 ||
    error_player(data, line, matches) == -1)
        return (0);
    replace(data, my_getnbr(line, data), my_getnbr(matches, data));
    data->status = 1;
    return (0);
}

int ai_turn(match_t *data)
{
    print_game(data);
    if (data->pipe_total == 0) {
        my_printf("You lost, too bad...\n");
        data->win = 2;
        return (2);
    }
    my_printf("\nAI's turn...\n");
    ai_game(data);
    my_printf("AI removed %d match(es) from line %d\n",
    data->ai_matches, data->ai_rand);
    data->yours = 0;
    data->status = 0;
}

int game(match_t *data)
{
    size_t buffsize = 4096;
    char *buffer = malloc(sizeof(char) * buffsize);
    data->long_of_lines = ((data->lines * 2));

    while (1) {
        if (data->status == 0 || data->status == 1)
            print_game(data);
        search_pipe_total(data);
        if (data->status == 0 || data->status == 2)
            if (perso_turn(data) == 1)
                return (0);
        search_pipe_total(data);
        if (data->status == 1)
            if (ai_turn(data) == 2)
                return (2);
    }
    return (0);
}