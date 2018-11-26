# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/24 10:47:34 by flfinet      #+#   ##    ##    #+#        #
#    Updated: 2018/11/22 16:50:17 by flfinet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror -Iincludes/

SRC	= srcs/main.c \
	  srcs/tools_error.c \
	  srcs/detection1.c \
	  srcs/detection2.c \
	  srcs/detection3.c \
	  srcs/detection4.c \
	  srcs/check_general.c \
	  srcs/check_error.c 

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	 gcc -o  $(NAME) $(CFLAGS) $(OBJS) libft/libft.a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
