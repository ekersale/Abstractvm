##
## Makefile for my_script in /home/kersal_e/projet_actuels/PSU_2013_myscript
## 
## Made by Elliot Kersale
## Login   <kersal_e@epitech.net>
## 
## Started on  Mon Feb 17 15:20:20 2014 Elliot Kersale
## Last update Thu Feb 27 11:21:57 2014 Elliot Kersale
##

SRCS		=	./sources/main.cpp		\
			./sources/parsing.cpp		\
			./sources/calculator.cpp

OBJS		=	$(SRCS:.cpp=.o)

CC		=	g++

INC		=	./includes

CPPFLAGS	=	-I $(INC)

NAME		=	avm

RM		=	rm -rf

$(NAME)		:	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

all		:	fclean $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
