/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
** File description:
** matchstick
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myprintf.h"

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct match_s {
    char **map;
    int nb_rm_max;
    int lines;
    int long_of_lines;
    int yours;
    int status;
    int pipe_total;
    int ai_rand;
    int ai_matches;
    int win;
    int debug;
} match_t;

void print_game(match_t *data);
void print_space(match_t *data);
void print_game_board(char **av, match_t *data);
int my_getnbr(char const *str, match_t *data);
int usage(int ac, char **av, match_t *data);
int error(int ac, char **av, match_t *data);
int game(match_t *data);
char *remove_backn(char *str);
int my_strlen(char const *str);
int search_pipe_in_line(match_t *data, int line, int matches);
int error_line(match_t *data, char *line);
int error_matches(match_t *data, char *matches);
int error_player(match_t *data, char *line, char *matches);
int replace(match_t *data, int line, int matches);
int search_pipe_total(match_t *data);
int ai_game(match_t *data);
int ai_check(match_t *data);
int ai_remove(match_t *data);
int perso_turn(match_t *data);
int your_turn(match_t *data);

#endif /* !MATCHSTICK_H_ */