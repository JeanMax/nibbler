// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:38:00 by mc                #+#    #+#             //
//   Updated: 2017/10/02 15:10:20 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

# define FRUIT_SCORE 3
# define BONUS_SCORE 7 //TODO: this is supposed to be a timer

# include "game_util.hpp"
# include "Map.hpp"
# include <string>
# include <list>
# include <climits>

class Player {
    public:
        Player(
            const std::string &name = "SnakeMan",
            enum player player = PLAYER_A,
            const Map *map = NULL
        );
        Player(Player const &copy);
        ~Player(void);
        Player const &operator=(Player const &copy);

        const std::string &getName() const;
        bool               isAlive() const;
        t_uint             getScore() const;
        enum direction     getDirection() const;

        void               turn(enum direction direction);
        void               moveForward();

    private:
        void               _move(enum direction direction);
        void               _eat(game_entity *entity);
        void               _poop();
        void               _die();

        const std::string        _name;
        std::list<game_entity *> _body;
        t_uint                   _score;
        enum direction           _direction;
        enum player              _player;
        t_uint                   _x;
        t_uint                   _y;
        const Map               *_map;
};

#endif // PLAYER_HPP
