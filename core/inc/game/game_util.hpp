// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game_util.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:46:24 by mc                #+#    #+#             //
//   Updated: 2018/04/14 20:42:59 by mcanal           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_UTIL_HPP
# define GAME_UTIL_HPP

# include "log.hpp"

# define ABS(x) ((x) > 0 ? (x) : (-x))

typedef unsigned int t_uint;

enum game_entity : char {
    OUTER_WALL = '\0',
    INNER_WALL = 'X',
    FOOD = 'o',
    BONUS = '0',
    SNAKE_A = 'a',
    SNAKE_B = 'b',
    SNAKE_C = 'c',
    SNAKE_D = 'd',
    HEAD_A = 'A',
    HEAD_B = 'B',
    HEAD_C = 'C',
    HEAD_D = 'D',
    EMPTY = ' ',
};

enum direction {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE,
};

enum player {
    PLAYER_A = 0,
    PLAYER_B = 1,
    PLAYER_C = 2,
    PLAYER_D = 3,
};
# define MAX_PLAYERS 4

enum key {
    KEY_LEFT_A =   0,
    KEY_RIGHT_A =  1,
    KEY_LEFT_B =   2,
    KEY_RIGHT_B =  3,
    KEY_LEFT_C =   4,
    KEY_RIGHT_C =  5,
    KEY_LEFT_D =   6,
    KEY_RIGHT_D =  7,
    KEY_EXIT =     8,
    KEY_LIB_A =    9,
    KEY_LIB_B =   10,
    KEY_LIB_C =   11,
    KEY_NONE =    12
};

#endif // GAME_UTIL_HPP
