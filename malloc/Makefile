# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboutin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 14:32:34 by pboutin           #+#    #+#              #
#    Updated: 2017/09/25 14:43:35 by pboutin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   scop

SOURCES     =   src/ft_free.c \
				src/large_function.c \
				src/lst_function.c \
				src/mmap.c \
				src/small_function.c \
				src/tiny_function.c 

OBJECTS =   $(subst .c,.o,$(SOURCES))

WFLAGS  =   -I ~/.brew/include

FLAGS   =   -framework OpenGL -lglfw -lGLEW

LDFLAGS =   -L ~/.brew/lib

CC      =   gcc

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
