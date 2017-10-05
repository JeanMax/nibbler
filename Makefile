#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2017/10/04 16:28:13 by mc               ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##
## CUSTOM CONFIG
##

# name of the binary to make
NAME =		nibbler

# file-names of the sources
SRCS =      main.cpp			\
			load_libs.cpp		\
			game_loop.cpp		\
								\
			parse_argv.cpp		\
			flag_parsers.cpp	\
								\
			Map.cpp				\
			Player.cpp			\
			Game.cpp

# folder-names of the sources (':' separated list)
VPATH =		core/src:core/src/argv_parser:core/src/game

# where are your tests?
TEST_DIR =	test

# # libft
# LFT_DIR =	libft
# LFT_I_DIR = -I$(LFT_DIR)/inc
# LFT =		$(LFT_DIR)/libft.a
# LFT_LIB =	-L$(LFT_DIR) -lft

# sdl
SDL_DIR =	sdl
SDL_I_DIR = -I$(SDL_DIR)/inc
SDL =		libdlsdl.so
SDL_LIB =	-rpath $(SDL_DIR) -L$(SDL_DIR) -ldlsdl

# sfml
SFML_DIR =	sfml
SFML_I_DIR = -I$(SFML_DIR)/inc
SFML =		libdlsfml.so
SFML_LIB =	-rpath $(SFML_DIR) -L$(SFML_DIR) -ldlsfml

# allegro
ALLEGRO_DIR =	allegro
ALLEGRO_I_DIR = -I$(ALLEGRO_DIR)/inc
ALLEGRO =		libdlallegro.so
ALLEGRO_LIB =	-rpath $(ALLEGRO_DIR) -L$(ALLEGRO_DIR) -ldlallegro

# folder-names containing headers files (prefix them with "-I")
I_DIR =		-Icore/inc	-Icore/inc/argv_parser	-Icore/inc/game	#$(SDL_I_DIR)	$(SFML_I_DIR) $(ALLEGRO_I_DIR)# $(LFT_I_DIR)

# extra libraries needed for linking
LIBS =		-ldl #$(SDL_LIB)	$(SFML_LIB)	$(ALLEGRO_LIB)	#$(LFT_LIB)		-lm



##
## GLOBAL VARIABLES
##

# folder used to store all compilations sub-products (.o and .d mostly)
O_DIR =		obj
OBJS =		$(SRCS:%.cpp=$(O_DIR)/%.o)
DEPS =		$(OBJS:%.o=%.d)

# specify flags for commands used in the following rules
RM =		rm -f
RMDIR =		rmdir -p
MKDIR =		mkdir -p
LN =		ln -s
UNLINK =	unlink
MAKE =		make
MAKEFLAGS =	-j
CXX =		$(shell clang --version &>/dev/null && echo clang++ || echo g++) -std=c++11
LD =		$(CXX)
CPPFLAGS =
CXXFLAGS =	-Wall -Wextra -Werror -O2
LDFLAGS =
LDLIBS =	$(LIBS)

# guess os and architecture
ifeq ($(OS), Windows_NT)
  CPPFLAGS += -D WIN32
  ifeq ($(PROCESSOR_ARCHITECTURE), AMD64)
    CPPFLAGS += -D AMD64
  else ifeq ($(PROCESSOR_ARCHITECTURE), x86)
    CPPFLAGS += -D IA32
  endif
else
  UNAME_S = $(shell uname -s)
  ifeq ($(UNAME_S), Linux)
    ECHO = echo -e
    CPPFLAGS += -D LINUX
  else ifeq ($(UNAME_S), Darwin)
    ECHO = echo
    CPPFLAGS += -D OSX
  endif
  UNAME_P = $(shell uname -p)
  ifeq ($(UNAME_P), unknown)
    UNAME_P = $(shell uname -m)
  endif
  ifeq ($(UNAME_P), x86_64)
    CPPFLAGS += -D AMD64
  else ifneq ($(filter %86, $(UNAME_P)), )
    CPPFLAGS += -D IA32
  else ifneq ($(filter arm%, $(UNAME_P)), )
    CPPFLAGS += -D ARM
  endif
endif

# some colors for pretty printing
WHITE =		\033[37;01m
RED =		\033[31;01m
GREEN =		\033[32;01m
YELLOW =	\033[33;01m
BLUE =		\033[34;01m
BASIC =		\033[0m

# default to silent Makefile, but you can run ´VERBOSE=t make´
ifdef VERBOSE
CPPFLAGS += -D VERBOSE
else
.SILENT:
endif



##
## PUBLIC RULES
##

# just to avoid conflicts between rules and files/folders names
.PHONY: all debug sanitize me_cry re clean fclean mrproper test

# classic build
all: $(O_DIR)
#	$(MAKE) -C $(LFT_DIR) $(FLAGS)
	$(MAKE) -C $(SDL_DIR) $(FLAGS)
	$(MAKE) -C $(SFML_DIR) $(FLAGS)
	$(MAKE) -C $(ALLEGRO_DIR) $(FLAGS)
	test -L $(SDL) || $(LN) $(SDL_DIR)/$(SDL) $(SDL)
	test -L $(SFML) || $(LN) $(SFML_DIR)/$(SFML) $(SFML)
	test -L $(ALLEGRO) || $(LN) $(ALLEGRO_DIR)/$(ALLEGRO) $(ALLEGRO)
	$(MAKE) $(NAME) $(FLAGS)

# build for gdb/valgrind debugging
debug: FLAGS = "CXXFLAGS = -g -ggdb -D DEBUG_MODE"
debug: all

# build for clang runtime debugging (fsanitize)
sanitize: FLAGS = "CXXFLAGS = -g -ggdb -D DEBUG_MODE -fsanitize=address,undefined -ferror-limit=5"
sanitize: all

# masochist build
me_cry: FLAGS = "CXXFLAGS = -Wall -Werror -Wextra -Wpedantic -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wcast-align -Wconversion -Wshadow -Weffc++ -Wredundant-decls -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Winline -Wunreachable-code" #-Wcast-qual
me_cry: all

# clean build and recompile with previous flags
re: FLAGS = $(PREV_FLAGS)
re: fclean all

# run tests on project
test: all
	$(MAKE) -C $(TEST_DIR) #TODO: handle flags

# remove all generated .o and .d
clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)

# remove the generated binary, and all .o and .d
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(SDL_DIR) fclean
	$(MAKE) -C $(SFML_DIR) fclean
	$(MAKE) -C $(ALLEGRO_DIR) fclean
	test -L $(SDL) && $(UNLINK) $(SDL) || true
	test -L $(SFML) && $(UNLINK) $(SFML) || true
	test -L $(ALLEGRO) && $(UNLINK) $(ALLEGRO) || true

# just clean everything this Makefile could have generated
mrproper: fclean
	test -d $(O_DIR) && $(RMDIR) $(O_DIR) || true
	$(MAKE) -C $(TEST_DIR) mrproper
	$(MAKE) -C $(SDL_DIR) mrproper
	$(MAKE) -C $(SFML_DIR) mrproper
	$(MAKE) -C $(ALLEGRO_DIR) mrproper
#	$(MAKE) -C $(LFT_DIR) fclean



##
## PRIVATE RULES
##

# read dependencies list generated by -MMD flag
-include $(DEPS)

# create binary (link)
$(NAME): $(OBJS)
	@$(ECHO) "$(BLUE)$(OBJS) $(LDLIBS) $(WHITE)->$(RED) $@ $(BASIC)"
	$(CXX) $(CXXFLAGS) $(I_DIR) $(OBJS) $(LDLIBS) -o $@ $(LDFLAGS)
	@$(ECHO) "$(WHITE)ldflags:$(BASIC) $(LDFLAGS)"
	@$(ECHO) "$(WHITE)cxxflags:$(BASIC) $(CXXFLAGS)"
	@$(ECHO) "$(WHITE)cppflags:$(BASIC) $(CPPFLAGS)"
	@$(ECHO) "$(WHITE)compi:$(BASIC) $(CXX)"

# create object files (compile)
$(O_DIR)/%.o: %.cpp
	@$(ECHO) "$(WHITE)$<\t->$(BLUE) $@ $(BASIC)"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(I_DIR) -MMD -c $< -o $@

# create directory for compilation sub-products
$(O_DIR):
	$(MKDIR) $(O_DIR)
