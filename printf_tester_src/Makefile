# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 17:56:29 by wxuerui           #+#    #+#              #
#    Updated: 2022/07/24 12:24:31 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

NAME	= libftprintf.a
LIBFT_DIR	= libft
LIBFT	= libft.a
CC	= gcc
HEADER	= -I $(SRCS_DIR)ft_printf.h 
CFLAGS	= -Wall -Werror -Wextra
AR	= ar rcs
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
BONUS_DIR	= bonus/

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

SRCS_FILES	=	ft_printf ft_print_hex ft_putunsign ft_putvoidptr ft_putcharf ft_putnbrf ft_putstrf ft_get_flags ft_printf_utils ft_putnbrstrf
BONUS_FILES	=	ft_printf_bonus ft_print_hex_bonus ft_putunsign_bonus ft_putvoidptr_bonus ft_putcharf_bonus ft_putnbrf_bonus ft_putstrf_bonus ft_get_flags_bonus ft_printf_utils_bonus ft_putnbrstrf_bonus

SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
BONUS	= $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
BOBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))

########

all:	$(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):	mkdir_objs create_libft $(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:	mkdir_objs create_libft $(BOBJS)
		$(AR) $(NAME) $(BOBJS)

create_libft:
				make -C $(LIBFT_DIR)
				cp $(LIBFT_DIR)/$(LIBFT) .
				mv $(LIBFT) $(NAME)

mkdir_objs:
			mkdir -p $(OBJS_DIR)

clean:
		rm -rf $(OBJS_DIR)
		make fclean -C $(LIBFT_DIR)

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(LIBFT)

re:	fclean all

.PHONY:	all clean fclean re
