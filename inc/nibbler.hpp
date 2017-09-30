// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   nibbler.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 14:37:01 by mc                #+#    #+#             //
//   Updated: 2017/09/30 20:53:44 by mc               ###   ########.fr       //
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
enum lib {
    LIB_A = 0,
    LIB_B = 1,
    LIB_C = 2,
}; //TODO

/*
** this struct will hold the parsed command-line arguments
*/
typedef struct s_args       t_args;
struct                      s_args
{
    int         width;
    int         height;
    enum lib    lib;
    const char *bin_name;
};
extern t_args g_parsed_args;


/*
** ARGV_PARSER
** argv_parser.cpp
*/
bool     parse_argv(const char **av);

#endif // NIBBLER_HPP
