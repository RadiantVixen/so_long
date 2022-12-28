# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 12:32:03 by aatki             #+#    #+#              #
#    Updated: 2022/12/27 18:33:44 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = so_long.c get_next_line.c get_next_line_utils.c zone.c map.c so_long_utils.c window.c move_image.c map_utils.c

SRCB = bonus/so_long_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/zone_bonus.c bonus/map_bonus.c bonus/so_long_utils_bonus.c bonus/window_bonus.c bonus/move_image_bonus.c bonus/map_utils_bonus.c bonus/bonuss_bonus.c

CC = cc

MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror 

all : ${NAME}

bonus : ${NAME_BONUS}

${NAME} : ${SRC}
	$(CC) ${MLX} ${SRC} -o $(NAME)

${NAME_BONUS} : ${SRCB}
	$(CC) ${MLX} ${SRCB} -o $(NAME_BONUS)

clean :
	rm -f ${OBJ}

fclean :clean
	rm -f ${NAME} ${NAME_BONUS}

re : fclean all
