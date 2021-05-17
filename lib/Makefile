##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyprintf-maxime.hoffbeck
## File description:
## Makefile
##

SRC	=	my/my_printf.c		\
		my/my_print_nbr.c	\
		my/my_print_char.c	\
		my/my_print_str.c	\
		my/my_puts.c		\
		my/my_print_unsigned_nbr.c		\
		my/my_print_octal.c			\
		my/my_print_binary.c			\
		my/my_print_octa_str.c			\
		my/my_pourcent.c				\
		my/my_print_hexa.c				\
		my/my_print_hexa_maj.c			\
		my/my_getnbr.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all	: $(NAME)

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME)
		rm ../$(NAME)

re : fclean all