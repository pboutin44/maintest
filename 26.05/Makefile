# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboutin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 11:02:28 by pboutin           #+#    #+#              #
#    Updated: 2017/07/26 17:21:01 by pboutin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	scop

SOURCES		=	src/main.c \
				src/parser2.c \
				src/matrix_ope.c \
				src/matrix_base.c \
				src/matrix_proj.c \
				src/color_loop_divers.c \
				src/norm_loop_1.c \
				src/norm_loop_2_invers.c \
				src/norm_invers_windows.c \
				src/shader.c \
				src/divers.c \
				src/divers2.c \
				src/divers3.c \
				src/points_norm1.c \
				src/points_norm2.c

OBJECTS	=	$(subst .c,.o,$(SOURCES))

WFLAGS	=	-I ~/.brew/include

FLAGS	=	-framework OpenGL -lglfw -lGLEW

LDFLAGS	=	-L ~/.brew/lib

CC		=	gcc

.SILENT:

$(NAME): $(OBJECTS)
	$(CC) $(WFLAGS) $(LDFLAGS)  $(FLAGS) $(SOURCES) -o scop
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

all: $(NAME)

%.o: %.c
	$(CC) $(WFLAGS) -c -o $@ $^
	printf "\e[32m[✔]\e[36m $@ "
	printf "\033[0m\n"

clean:
	rm -Rf $(OBJECTS)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	rm -Rf $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

PHONY: re fclean clean all
