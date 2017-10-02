# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 20:33:18 by bmbarga           #+#    #+#              #
#    Updated: 2017/10/02 15:13:28 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

LIBSDL = libdlsdl.so

LIBSFML = libdlsfml.so

LIBALLEGRO = libdlallegro.so

MAIN_DIR =
SDL_DIR = sdl/
SFML_DIR = sfml/
ALLEGRO_DIR = allegro/
SHARED_DIR = shared/

MAIN = main.cpp
SDL = DlSdl.class.cpp
SFML = DlSfml.class.cpp
ALLEGRO = DLAllegro.class.cpp
SHARED = IDL.class.cpp

MAINS = $(addprefix $(MAIN_DIR), $(MAIN))
SDLS = $(addprefix $(SDL_DIR), $(SDL))
SFMLS = $(addprefix $(SFML_DIR), $(SFML))
ALLEGROS = $(addprefix $(ALLEGRO_DIR), $(ALLEGRO))
SHAREDS = $(addprefix $(SHARED_DIR), $(SHARED))

LIBPATH = -L./

INCPATH = ./

INCS = -I $(addprefix $(INCPATH), $(SHARED_DIR)) \
		-I $(addprefix $(INCPATH), $(SDL_DIR)) \
		-I $(addprefix $(INCPATH), $(SFML_DIR)) \
		-I $(addprefix $(INCPATH), $(ALLEGRO_DIR))

FLAGS = -Wall -Werror -Wextra

SDL_LIB_DIR = ../SDL2-2.0.6
SDL_LIB = `./$(SDL_LIB_DIR)/sdl2-config --libs`
SDL_I_DIR = `./$(SDL_LIB_DIR)/sdl2-config --cflags`

FLAGLIB = -fPIC -shared

CC = g++

all : $(NAME)

$(NAME) : libs
	$(CC) $(FLAG) $(INCS) $(LIBPATH) -o $(NAME) $(MAINS)

libs: $(LIBSDL) $(LIBSFML) $(LIBALLEGRO)

$(LIBSDL):
	$(CC) $(FLAGS) $(FLAGLIB) $(INCS) $(SDL_I_DIR) -o $(LIBSDL) $(SHAREDS) $(SDLS) $(SDL_LIB)

$(LIBSFML):
	$(CC) $(FLAGS) $(FLAGLIB) $(INCS) -o $(LIBSFML) $(SHAREDS) $(SFMLS)

$(LIBALLEGRO):
	$(CC) $(FLAGS) $(FLAGLIB) $(INCS) -o $(LIBALLEGRO) $(SHAREDS) $(ALLEGROS)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(LIBSFML) $(LIBSDL) $(LIBALLEGRO)

re: fclean all
