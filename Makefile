#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2017/10/01 22:40:57 by mc               ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##
## CUSTOM CONFIG
##

# name of the binary to make
NAME =		nibbler

# file-names of the sources
SRCS =      main.cpp			\
								\
			parse_argv.cpp		\
			flag_parsers.cpp	\
								\
			Map.cpp				\
			Player.cpp

# folder-names of the sources (':' separated list)
VPATH =		src:src/argv_parser:src/game

# where are your tests?
TEST_DIR =	test

# sdl
SDL_DIR =	SDL2-2.0.6
SDL_INSTALL_DIR = $(PWD)/$(SDL_DIR)/install
SDL_ARCHIVE = SDL2-2.0.6.tar.gz
SDL_URL =	https://www.libsdl.org/release/$(SDL_ARCHIVE)
SDL_I_DIR =	`./$(SDL_DIR)/sdl2-config --cflags`
SDL_LIB =	`./$(SDL_DIR)/sdl2-config --libs`
SDL =		$(SDL_INSTALL_DIR)/lib/libSDL2.la

# sfml
SFML_DIR =	SFML-2.4.2
SFML_INSTALL_DIR = $(PWD)/$(SFML_DIR)/install
SFML_ARCHIVE = SFML-2.4.2-sources.zip
SFML_URL =	 https://www.sfml-dev.org/files/$(SFML_ARCHIVE)
SFML_I_DIR = -I$(SFML_DIR)/include/SMFL
SFML_LIB =	-L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system # -lsfml-audio -lsfml-network
SFML =		$(SFML_INSTALL_DIR)/lib/libsfml-graphics.so

# # libft
# LFT_DIR =	libft
# LFT_I_DIR = -I$(LFT_DIR)/inc
# LFT =		$(LFT_DIR)/libft.a
# LFT_LIB =	-L$(LFT_DIR) -lft

# folder-names containing headers files (prefix them with "-I")
I_DIR =		-Iinc	-Iinc/argv_parser	-Iinc/game	$(SDL_I_DIR)	$(SFML_I_DIR)	#$(LFT_I_DIR)

# extra libraries needed for linking
LIBS =		$(SDL_LIB)		$(SFML_LIB)		#$(LFT_LIB)		-lm



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
CURL =		curl -LO
UNTAR =		tar -xvf
UNZIP =		unzip
MAKE =		make
MAKEFLAGS =	-j
CXX =		$(shell clang --version &>/dev/null && echo clang++ || echo g++) -std=c++11
CPPFLAGS =	-Wall -Wextra -Werror -O2
LD =		$(CXX)
LDFLAGS =	$(CPPFLAGS)
LDLIBS =	$(LIBS)

# guess os and architecture
ifeq ($(OS), Windows_NT)
  CCFLAGS += -D WIN32
  ifeq ($(PROCESSOR_ARCHITECTURE), AMD64)
    CCFLAGS += -D AMD64
  else ifeq ($(PROCESSOR_ARCHITECTURE), x86)
    CCFLAGS += -D IA32
  endif
else
  UNAME_S = $(shell uname -s)
  ifeq ($(UNAME_S), Linux)
    ECHO = echo -e
    CCFLAGS += -D LINUX
  else ifeq ($(UNAME_S), Darwin)
    ECHO = echo
    CCFLAGS += -D OSX
  endif
  UNAME_P = $(shell uname -p)
  ifeq ($(UNAME_P), unknown)
    UNAME_P = $(shell uname -m)
  endif
  ifeq ($(UNAME_P), x86_64)
    CCFLAGS += -D AMD64
  else ifneq ($(filter %86, $(UNAME_P)), )
    CCFLAGS += -D IA32
  else ifneq ($(filter arm%, $(UNAME_P)), )
    CCFLAGS += -D ARM
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
CCFLAGS += -D VERBOSE
else
.SILENT:
endif



##
## PUBLIC RULES
##

# just to avoid conflicts between rules and files/folders names
.PHONY: all debug sanitize me_cry re clean fclean mrproper test sdl sfml

# classic build
all: $(O_DIR)
#	$(MAKE) -C $(LFT_DIR) $(FLAGS)
	$(MAKE) sdl
	$(MAKE) sfml
	$(MAKE) $(NAME) $(FLAGS)

# build for gdb/valgrind debugging
debug: FLAGS = "CPPFLAGS = -g -ggdb"
debug: all

# build for clang runtime debugging (fsanitize)
sanitize: FLAGS = "CPPFLAGS = -g -ggdb -fsanitize=address,undefined -ferror-limit=5"
sanitize: all

# masochist build
me_cry: FLAGS = "CPPFLAGS = -Wall -Werror -Wextra -Wpedantic -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wcast-align -Wconversion -Wshadow -Weffc++ -Wredundant-decls -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Winline" #-Wcast-qual
me_cry: all

# clean build and recompile with previous flags
re: FLAGS = $(PREV_FLAGS)
re: fclean all

# run tests on project
test: all
	$(MAKE) -C $(TEST_DIR) #TODO: handle flags

# install sdl
sdl: $(SDL)

# install sfml
sfml: $(SFML)

# remove all generated .o and .d
clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RM) $(SDL_ARCHIVE)
	$(RM) $(SFML_ARCHIVE)

# remove the generated binary, and all .o and .d
fclean: clean
	$(RM) $(NAME)
#	test -e $(SDL_DIR) && $(MAKE) -C $(SDL_DIR) distclean || true
#	test -e $(SFML_DIR) && $(MAKE) -C $(SFML_DIR) clean || true

# just clean everything this Makefile could have generated
mrproper: fclean
	test -d $(O_DIR) && $(RMDIR) $(O_DIR) || true
	$(RM) -r $(SDL_DIR)
	$(RM) -r $(SFML_DIR)
	$(MAKE) -C $(TEST_DIR) mrproper
#	$(MAKE) -C $(LFT_DIR) fclean



##
## PRIVATE RULES
##

# read dependencies list generated by -MMD flag
-include $(DEPS)

# create binary (link)
$(NAME): $(OBJS)
	@$(ECHO) "$(BLUE)$(OBJS) $(LIBS) $(WHITE)->$(RED) $@ $(BASIC)"
	$(CXX) $(LDFLAGS) $(I_DIR) $(OBJS) $(LDLIBS) -o $@
	@$(ECHO) "$(WHITE)cppflags:$(BASIC) $(CPPFLAGS)"
	@$(ECHO) "$(WHITE)ccflags:$(BASIC) $(CCFLAGS)"
	@$(ECHO) "$(WHITE)compi:$(BASIC) $(CXX)"

# create object files (compile)
$(O_DIR)/%.o: %.cpp
	@$(ECHO) "$(WHITE)$<\t->$(BLUE) $@ $(BASIC)"
	$(CXX) $(CCFLAGS) $(CPPFLAGS) $(I_DIR) -MMD -c $< -o $@

# create directory for compilation sub-products
$(O_DIR):
	$(MKDIR) $(O_DIR)

# install sdl
$(SDL):
	test -d $(SDL_DIR) || $(CURL) $(SDL_URL)
	test -d $(SDL_DIR) || $(UNTAR) $(SDL_ARCHIVE)
	cd $(SDL_DIR) && ./configure --prefix=$(SDL_INSTALL_DIR)
	$(MAKE) -C $(SDL_DIR)
	$(MAKE) -C $(SDL_DIR) install

# install sfml
$(SFML):
	test -d $(SFML_DIR) || $(CURL) $(SFML_URL)
	test -d $(SFML_DIR) || $(UNZIP) $(SFML_ARCHIVE)
	$(MKDIR) $(SFML_INSTALL_DIR)
	cd $(SFML_DIR) && cmake -D CMAKE_INSTALL_PREFIX=$(SFML_INSTALL_DIR) .
	$(MAKE) -C $(SFML_DIR)
	$(MAKE) -C $(SFML_DIR) install
