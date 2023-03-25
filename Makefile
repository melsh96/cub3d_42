# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 11:15:20 by meshahrv          #+#    #+#              #
#    Updated: 2023/03/25 15:15:03 by meshahrv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_PATH		= src/
OBJ_PATH		= obj/

CC 				= cc
CFLAGS			= -Wall -Werror -Wextra -MMD -MP -g3

SRC				= main.c \

SRC_PREFIXED	= $(addprefix $(SRC_PATH), $(SRC))
OBJ				= $(SRC:.c=.o)
OBJ_PREFIXED	= $(addprefix $(OBJ_PATH), $(OBJ))
DEPS			= $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})
INCS			= -I./includes/ #-I./minilibx-linux/
LIB 			= -L./libft_42/ -lft

RM 				= rm -rf

####### COLORS #######

GREEN = "\033[38;5;150m"
CYAN = "\033[38;5;140m"
BOLD = "\033[1m"
NC = "\033[0m"

all:	${NAME}

# ${NAME}: ${OBJ_PREFIXED}
# 	@make -C minilibx-linux all
# 	@make -C libft_42
# 	@${CC} $(CFLAGS) ${OBJ_PREFIXED} ${LIB} -o ${NAME} -Lminilibx-linux -lmlx -lXext -lX11
# 	@echo ${CYAN}${BOLD}so_long${NC} [${GREEN}OK${NC}] Compiling So_Long Objects ${NC}

${NAME}: ${OBJ_PREFIXED}
	make -C ./libft_42
	${CC} $(CFLAGS) ${OBJ_PREFIXED} ${LIB} -o ${NAME}
	@echo ${CYAN}${BOLD}CUB3D${NC} [${GREEN}OK${NC}] Compiling Objects : ${BOLD}CUB3D${NC}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p ${OBJ_PATH}
	${CC} ${CFLAGS} ${INCS} -o $@ -c $<

# clean:
# 	@make $@ --no-print-directory -C minilibx-linux clean
# 	@${RM} ${OBJ_PATH}
# 	@echo ${CYAN}${BOLD}CUB3D${NC} [${GREEN}OK${NC}] Cleaning Objects : ${BOLD}CUB3D${NC}

clean:
	@${RM} ${OBJ_PATH}
	@echo ${CYAN}${BOLD}CUB3D${NC} [${GREEN}OK${NC}] Cleaning Objects : ${BOLD}CUB3D${NC}

fclean:	clean
	make $@ -C ./libft_42
	@rm -f ${NAME}
	@echo ${CYAN}${BOLD}CUB3D${NC} [${GREEN}OK${NC}] Cleaning All Objects : ${BOLD}CUB3D${NC}

re: fclean all

-include ${DEPS}

.PHONY : all clean fclean re