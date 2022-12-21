# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 12:32:03 by aatki             #+#    #+#              #
#    Updated: 2022/12/21 22:26:51 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c get_next_line.c get_next_line_utils.c zone.c map.c so_long_utils.c window.c move_image.c

CC = cc

MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror 

SGV = -fsanitize=address

AR = ar -rc

OBJ = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${SRC}
	$(CC) ${MLX} ${SRC} -o $(NAME)

%.o : %.c
	${CC} ${CFLAGS}   -c ${SRC}

clean :
	rm -f ${OBJ}

fclean :clean
	rm -f ${NAME}

re : fclean all
