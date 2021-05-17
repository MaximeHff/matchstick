##
## EPITECH PROJECT, 2021
## B-CPE-200-STG-2-1-matchstick-maxime.hoffbeck
## File description:
## Makefile
##

SRC=	src/matchstick.c			\
		src/print.c					\
		src/tools.c					\
		src/error.c					\
		src/ai.c					\
		src/game.c					\
		src/search.c				\
		src/error_game.c			\

OBJ=	$(SRC:.c=.o)

NAME=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib
	gcc $(SRC) -g -o $(NAME) -Llib -lmy

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/ fclean

re: fclean