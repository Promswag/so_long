# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 14:35:47 by gbaumgar          #+#    #+#              #
#    Updated: 2022/09/28 12:17:44 by gbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

INCLUDE_DIR		= ./include/
SRC_DIR			= ./src/
OUT_DIR			= ./

SRC				= 	so_long.c sl_map.c sl_draw.c sl_key_hook.c sl_error.c sl_path_check.c sl_misc.c \
					get_next_line.c get_next_line_utils.c
OBJS			= ${SRC:%.c=${OUT_DIR}%.o}

INCLUDE			= -I${INCLUDE_DIR}	
LIB_MLX			= -L /usr/local/lib -lmlx
LIB_FT			= -L libft -lft
LIB_PRINTF		= -L ft_printf -lftprintf

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all: ${NAME}

${NAME}: ${OBJS}
	make -C libft
	make -C ft_printf
	${CC} -o ${NAME} ${LIB_FT} ${LIB_PRINTF} ${LIB_MLX} -framework OpenGL -framework AppKit ${INCLUDE} ${OBJS}

${OUT_DIR}%.o: ${SRC_DIR}%.c 
	${CC} ${CFLAGS} ${INCLUDE} $< -c -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	${RM} ${OBJS}

fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	${RM} ${NAME}

re: fclean ${NAME}

bonus:	all

.PHONY:	all clean fclean re bonus
