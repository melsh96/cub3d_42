# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 11:58:02 by meshahrv          #+#    #+#              #
#    Updated: 2023/01/17 18:53:51 by meshahrv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH		= libft/
OBJ_PATH		= objs/
GNL_PATH		= get_next_line/
PRINTF_PATH 	= ft_printf/
GB_COLLECT_PATH	= garbage_collector/

SRC = ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_llatoi.c \

SRC_GNL = get_next_line_bonus.c\
			get_next_line_utils_bonus.c

SRC_PRINTF = ft_printf.c \
				printf_printnbrs.c \
				printf_utils.c \

SRC_GB_COLLECT = garbage_collector.c
			
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
GNL			= $(addprefix $(GNL_PATH), $(SRC_GNL))
PRINTF		= $(addprefix $(PRINTF_PATH), $(SRC_PRINTF))
GB_COLLECT	= $(addprefix $(GB_COLLECT_PATH), $(SRC_GB_COLLECT))
OBJ			= $(SRC:.c=.o)
OBJS_GNL 	= $(SRC_GNL:.c=.o)
OBJS_PRINTF	= $(SRC_PRINTF:.c=.o)
OBJS_GB		= $(SRC_GB_COLLECT:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ) $(OBJS_GNL) $(OBJS_PRINTF) $(OBJS_GB))
DEPS		= $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})

INCS	= -I./includes_libft/

COMPILER_COMMAND = cc

CFLAGS = -Wall -Werror -Wextra -MMD -MP

AR = ar rcs

RM = rm -rf

####### COLORS #######

GREEN = "\033[38;5;150m"
CYAN = "\033[38;5;140m"
BOLD = "\033[1m"
NC = "\033[0m"

all:	$(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@echo ${CYAN}${BOLD}LIBFT${NC} [${GREEN}OK${NC}] Compiling Objects : ${BOLD}LIBFT${NC}
	@echo ${CYAN}${BOLD}LIBFT${NC} [${GREEN}OK${NC}] Compiling Objects : ${BOLD}GET NEXT LINE${NC}
	@echo ${CYAN}${BOLD}LIBFT${NC} [${GREEN}OK${NC}] Compiling Objects : ${BOLD}FT_PRINTF${NC}
	@echo ${CYAN}${BOLD}LIBFT${NC} [${GREEN}OK${NC}] Compiling Objects : ${BOLD}GARBAGE COLLECTOR${NC}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INCS} -o $@ -c $<

$(OBJ_PATH)%.o: $(GNL_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INCS} -o $@ -c $<

$(OBJ_PATH)%.o: $(PRINTF_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INCS} -o $@ -c $<

$(OBJ_PATH)%.o: $(GB_COLLECT_PATH)%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} ${INCS} -o $@ -c $<

clean:
	@$(RM) ${OBJ_PATH}

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

-include ${DEPS}

.PHONY : all clean fclean re