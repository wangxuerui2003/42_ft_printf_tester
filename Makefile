# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 10:31:28 by wxuerui           #+#    #+#              #
#    Updated: 2022/07/24 11:04:00 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

NAME	= tester
LIBFTPRINTF_DIR = printf_tester_src/
LIBFTPRINTF = $(LIBFTPRINTF_DIR)libftprintf.a
CC	= gcc
HEADER = -I tester_header.h
CFLAGS	= -Wall -Werror -Wextra
OBJS_DIR	= objs/

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#sources

SRC_FILES	=	main run_test print_help utils utils2 get_file_content malloc_count

SRCS	= $(addsuffix .c, $(SRC_FILES))
OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

########

all:	$(NAME)

$(OBJS_DIR)%.o: %.c
				$(CC) $(CFLAGS) $(HEADER) -c $^ -o $@

$(NAME):	mkdir_objs $(OBJS)
			make -C $(LIBFTPRINTF_DIR)
			$(CC) $(CFLAGS) $(HEADER) -L$(LIBFTPRINTF_DIR) -o $(NAME) $(OBJS) -lftprintf -ldl

bonus:		mkdir_objs $(OBJS)
			make -C $(LIBFTPRINTF_DIR) bonus
			$(CC) $(CFLAGS) $(HEADER) -L$(LIBFTPRINTF_DIR) -o $(NAME) $(OBJS) -lftprintf -ldl

mkdir_objs:
			@mkdir -p $(OBJS_DIR)

clean:
		rm -rf $(OBJS_DIR)
		make -C $(LIBFTPRINTF_DIR) fclean

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re