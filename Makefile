# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 02:36:37 by jonchoi           #+#    #+#              #
#    Updated: 2023/03/18 13:21:52 by jonchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= pipex
NAME_B					= pipex_bonus


CC						= cc 
CFLAGS					= -Wall -Wextra -Werror	
AR						= ar rcs
RM						= rm -f

SRCS_DIR				= ./mandatory/
SRCS_DIR_B				= ./bonus/


UTILS_DIR				= utils/
UTILS_SRC				= ft_memset.c print_error.c ft_strncmp.c ft_split.c\
							ft_strjoin.c ft_memcpy.c ft_strlen.c\
#free_array.c\

UTILS_DIR_B				= utils/
UTILS_SRC_B				= ft_memset.c print_error.c ft_strncmp.c ft_split.c\
							ft_strjoin.c ft_memcpy.c ft_strlen.c\

GNL_DIR_B				= get_next_line/
GNL_SRC_B				= get_next_line_bonus.c get_next_line_utils_bonus.c\

SRC						=	main.c init.c parse.c pipex.c free.c\
							$(addprefix $(UTILS_DIR), $(UTILS_SRC))\

SRC_B					=	main_bonus.c parse_bonus.c init_bonus.c\
							parse_bonus.c pipex_bonus.c here_doc_bonus.c\
							free_bonus.c\
							$(addprefix $(UTILS_DIR_B), $(UTILS_SRC_B))\
							$(addprefix $(GNL_DIR_B), $(GNL_SRC_B))\


SRCS					=	$(addprefix $(SRCS_DIR), $(SRC))
SRCS_B					=	$(addprefix $(SRCS_DIR_B), $(SRC_B))

OBJS					=	$(SRCS:.c=.o)
OBJS_B					=	$(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

$(NAME_B) : $(OBJS_B)
		$(CC) $(CFLAGS) -o $@ $^

bonus	:	$(NAME_B)

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re :
	make fclean
	make all

.PHONY	:	all clean fclean re bonus
