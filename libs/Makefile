# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 20:33:18 by bmbarga           #+#    #+#              #
#    Updated: 2017/10/03 19:05:22 by bmbarga          ###   ########.fr        #
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
MAP_DIR = ../core/src/game/

MAIN = main.cpp
SDL = DlSdl.class.cpp
SFML = DlSfml.class.cpp
ALLEGRO = DLAllegro.class.cpp
SHARED = IDL.class.cpp
MAP = Map.cpp

MAINS = $(addprefix $(MAIN_DIR), $(MAIN))
SDLS = $(addprefix $(SDL_DIR), $(SDL))
SFMLS = $(addprefix $(SFML_DIR), $(SFML))
ALLEGROS = $(addprefix $(ALLEGRO_DIR), $(ALLEGRO))
SHAREDS = $(addprefix $(SHARED_DIR), $(SHARED))
MAPS = $(addprefix $(MAP_DIR), $(MAP))

LIBPATH = -L./

INCPATH = ./

INCS = -I $(addprefix $(INCPATH), $(SHARED_DIR)) \
		-I $(addprefix $(INCPATH), $(SDL_DIR)) \
		-I $(addprefix $(INCPATH), $(SFML_DIR)) \
		-I $(addprefix $(INCPATH), $(ALLEGRO_DIR)) \
		-I ../core/inc \
		-I ../core/inc/game

FLAGS = -Wall -Werror -Wextra -std=c++11

SDL_LIB_DIR = ../sdl/SDL2-2.0.6
SDL_LIB = `./$(SDL_LIB_DIR)/sdl2-config --libs`
SDL_I_DIR = `./$(SDL_LIB_DIR)/sdl2-config --cflags`

FLAGLIB = -fPIC -shared

CC = g++

all : $(NAME)

$(NAME) : libs
	$(CC) $(FLAGS) $(INCS) $(LIBPATH) -o $(NAME) $(MAINS) $(MAPS)

libs: $(LIBSDL) $(LIBSFML) $(LIBALLEGRO)

$(LIBSDL):
	$(CC) $(FLAGS) $(FLAGLIB) $(INCS) $(SDL_I_DIR) -o $(LIBSDL) $(SHAREDS) $(SDLS) $(MAPS) $(SDL_LIB)

$(LIBSFML):
	$(CC) $(FLAGS) $(FLAGLIB) $(INCS) -o $(LIBSFML) $(SHAREDS) $(SFMLS) $(MAPS)

$(LIBALLEGRO):
	$(CC) $(FLAGS) $(FLAGLIB) $(INCS) -o $(LIBALLEGRO) $(SHAREDS) $(ALLEGROS) $(MAPS)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(LIBSFML) $(LIBSDL) $(LIBALLEGRO) $(MAP)

re: fclean all
