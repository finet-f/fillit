# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/24 10:47:34 by flfinet      #+#   ##    ##    #+#        #
#    Updated: 2018/10/31 14:03:40 by flfinet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror -Iincludes/

SRC	= srcs/main.c \
	  srcs/fill_list.c

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
