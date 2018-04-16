// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   argv_parser.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 16:27:44 by mc                #+#    #+#             //
//   Updated: 2018/04/16 17:47:25 by mcanal           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARGV_PARSER_HPP
# define ARGV_PARSER_HPP

# include "nibbler.hpp"
# include "Map.hpp" // for map limits

# define LIB_NAME_A "sdl"
# define LIB_NAME_B "sfml"
# define LIB_NAME_C "glfw"
# define AVAILABLE_LIB_NAMES LIB_NAME_A "/" LIB_NAME_B "/" LIB_NAME_C

# define DEFAULT_LIB      LIB_A
# define DEFAULT_LIB_NAME LIB_NAME_A

# define NUMBER_OF_FLAGS  4

# define DEFAULT_PLAYER_NAME "SnakeMan"

/*
** flag_parsers.cpp
*/
bool        parse_width(const char *s);
bool        parse_height(const char *s);
bool        parse_library(const char *s);
bool        parse_player_name(const char *s);


#endif // ARGV_PARSER_HPP
