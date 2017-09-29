// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   argv_parser.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 16:27:44 by mc                #+#    #+#             //
//   Updated: 2017/09/29 19:08:58 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARGV_PARSER_HPP
# define ARGV_PARSER_HPP

# include "nibbler.hpp"
# include <string.h>

# define LIB_NAME_A "sdl"
# define LIB_NAME_B "sdl" //TODO
# define LIB_NAME_C "sdl" //TODO
# define AVAILABLE_LIB_NAMES LIB_NAME_A "/" LIB_NAME_B "/" LIB_NAME_C

# define DEFAULT_WIDTH    16
# define DEFAULT_HEIGHT   16
# define DEFAULT_LIB      LIB_A
# define DEFAULT_LIB_NAME LIB_NAME_A

# define NUMBER_OF_FLAGS  3
enum argv_flags {
    WIDTH = 0,
    HEIGHT = 1,
    LIB_NAME = 2,
};

# define MIN_WIDTH  9
# define MAX_WIDTH  1000

# define MIN_HEIGHT 9
# define MAX_HEIGHT 1000



/*
** flag_parsers.cpp
*/
bool        parse_width(const char *s);
bool        parse_height(const char *s);
bool        parse_library(const char *s);


#endif // ARGV_PARSER_HPP
