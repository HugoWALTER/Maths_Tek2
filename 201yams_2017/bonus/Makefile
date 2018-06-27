##
## EPITECH PROJECT, 2018
## yams
## File description:
## Makefile
##

NAME    =       yams

SRC     =	srcs/window.c			\
		srcs/create_texture.c		\
		srcs/display_text.c		\
		srcs/create_dices.c		\
		srcs/create_score.c		\
		srcs/create_endscreen.c		\
		srcs/algo.c			\
		srcs/main.c

OBJ     =       $(SRC:.c=.o)

CC      =       gcc

CFLAGS  =       -I./include

LDFLAGS =       -W -Wall -Werror -lc_graph_prog_full -lm -g

RM      =       rm -rf

all:    $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

dbg: CFLAGS += -g
dbg: re
