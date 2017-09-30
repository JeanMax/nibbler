// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:46:24 by mc                #+#    #+#             //
//   Updated: 2017/09/30 22:49:14 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "log.hpp"

enum game_entity : char {
    OUTER_WALL = '\0',
    INNER_WALL = 'w',
    FRUIT = 'f',
    BONUS = 'b',
    SNAKE = 's',
    EMPTY = ' ',
};

typedef unsigned int t_uint;


#endif // GAME_HPP
