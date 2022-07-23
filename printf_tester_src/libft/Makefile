
#variables

NAME	= libft.a
CC	= gcc
AR	= ar rcs
HEADER	= -I libft.h
CFLAGS	= -Wall -Werror -Wextra $(HEADER)
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

#Colors

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

SRC_FILES	= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap ft_putnbr ft_putchar ft_putstr

SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

#######

OBJSF		=	.cache_exists

all:	$(NAME)

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c | $(OBJSF)
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
			mkdir -p $(OBJS_DIR)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS_DIR)
		rm -rf $(OBJSF)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
