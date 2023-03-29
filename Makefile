# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 11:15:20 by meshahrv          #+#    #+#              #
#    Updated: 2023/03/29 13:20:07 by meshahrv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_PATH		= src/
OBJ_PATH		= obj/
PARS_PATH		= src/parsing/
UTILS_PATH		= src/utils/

CC 				= cc
CFLAGS			= -Wall -Werror -Wextra -MMD -MP -g3

SRC				= main.c \

SRC_PARS		= parsing.c \

SRC_UTILS		= print_utils.c \

SRC_PREFIXED	= $(addprefix $(SRC_PATH), $(SRC))
PARS_PREFIXED	=$(addprefix $(PARS_PATH), $(SRC_PARS))
UTILS_PREFIXED	=$(addprefix $(UTILS_PATH), $(SRC_UTILS))

OBJ_SRC			= $(SRC:.c=.o)
OBJ_PARS		= $(SRC_PARS:.c=.o)
OBJ_UTILS		= $(SRC_UTILS:.c=.o)

OBJ_PREFIXED	= $(addprefix $(OBJ_PATH), $(OBJ_SRC) $(OBJ_PARS) $(OBJ_UTILS))
DEPS			= $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})
INCS			= -I./includes/ -I./minilibx-linux/
LIB 			= -L./libft_42/ -lft

RM 				= rm -rf

####### COLORS #######

GREEN = "\033[38;5;150m"
CYAN = "\033[38;5;140m"
BOLD = "\033[1m"
NC = "\033[0m"

all:	${NAME}

${NAME}: ${OBJ_PREFIXED}
	make -C minilibx-linux all
	make -C ./libft_42
	${CC} $(CFLAGS) ${OBJ_PREFIXED} ${LIB} -o ${NAME} -Lminilibx-linux -lmlx -lXext -lX11
	@echo ${CYAN}${BOLD}CUB3D${NC} [${GREEN}OK${NC}] Compiling Objects : ${BOLD}CUB3D${NC}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p ${OBJ_PATH}
	${CC} ${CFLAGS} ${INCS} -o $@ -c $<

$(OBJ_PATH)%.o: $(PARS_PATH)%.c
	mkdir -p ${OBJ_PATH}
	${CC} ${CFLAGS} ${INCS} -o $@ -c $<

$(OBJ_PATH)%.o: $(UTILS_PATH)%.c
	mkdir -p ${OBJ_PATH}
	${CC} ${CFLAGS} ${INCS} -o $@ -c $<

clean:
	@make $@ --no-print-directory -C minilibx-linux clean
	@${RM} ${OBJ_PATH}
	@echo ${CYAN}${BOLD}CUB3D${NC} [${GREEN}OK${NC}] Cleaning Objects : ${BOLD}CUB3D${NC}

fclean:	clean
	make $@ -C ./libft_42
	@rm -f ${NAME}
	@echo ${CYAN}${BOLD}CUB3D${NC} [${GREEN}OK${NC}] Cleaning All Objects : ${BOLD}CUB3D${NC}

re: fclean all

-include ${DEPS}

.PHONY : all clean fclean re