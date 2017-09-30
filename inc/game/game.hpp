// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:46:24 by mc                #+#    #+#             //
//   Updated: 2017/09/30 23:32:27 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "log.hpp"

# define FRUIT_SCORE 3
# define BONUS_SCORE 7 //TODO: this is supposed to be a timer

enum game_entity : char {
    OUTER_WALL = '\0',
    INNER_WALL = 'w',
    FRUIT = 'f',
    BONUS = 'b',
    SNAKE = 's',
    EMPTY = ' ',
};

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE,
};

typedef unsigned int t_uint;


#endif // GAME_HPP
