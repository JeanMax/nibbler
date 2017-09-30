// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game_util.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:46:24 by mc                #+#    #+#             //
//   Updated: 2017/10/01 01:15:43 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_UTIL_HPP
# define GAME_UTIL_HPP

# include "log.hpp"

typedef unsigned int t_uint;

enum game_entity : char {
    OUTER_WALL = '\0',
    INNER_WALL = 'w',
    FRUIT = 'f',
    BONUS = 'b',
    SNAKE_A = '1',
    SNAKE_B = '2',
    SNAKE_C = '3',
    SNAKE_D = '4',
    EMPTY = ' ',
};

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE,
};

enum player {
    PLAYER_A = 0,
    PLAYER_B = 1,
    PLAYER_C = 2,
    PLAYER_D = 3,
};
# define MAX_PLAYERS 4


#endif // GAME_UTIL_HPP
