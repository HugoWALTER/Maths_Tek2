##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 201yams
##

NAME	=	201yams

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

INCS	=	-I./include

LIBS	=	-lm

CFLAGS	=	$(INCS) $(LIBS)

CC	=	gcc

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
