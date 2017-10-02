// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   nibbler.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 14:37:01 by mc                #+#    #+#             //
//   Updated: 2017/10/03 00:27:03 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NIBBLER_HPP
# define NIBBLER_HPP

# include "log.hpp"
# include "Map.hpp"
# include <iostream>
# include <cstring>

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif // EXIT_SUCCESS

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif // EXIT_FAILURE


# define NUMBER_OF_LIBS  3
enum lib { //TODO
    LIB_A = 0,
    LIB_B = 1,
    LIB_C = 2,
};

/*
** this struct will hold the parsed command-line arguments
*/
typedef struct s_args       t_args;
struct                      s_args
{
    t_uint      width;
    t_uint      height;
    enum lib    lib;
    const char *bin_name;
    const char *players_names[MAX_PLAYERS + 1];
};
extern t_args g_parsed_args;



/*
** BASE
** game_loop.cpp
*/
bool launch_game(const t_uint width,
                 const t_uint height,
                 const char **players_names);

/*
** ARGV_PARSER
** argv_parser.cpp
*/
bool     parse_argv(const char **av);


#endif // NIBBLER_HPP
