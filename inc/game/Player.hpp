// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:38:00 by mc                #+#    #+#             //
//   Updated: 2017/09/30 23:29:04 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "game.hpp"
# include <string>
# include <list>

class Player {
    public:
        Player(const std::string &name = "SnakeMan");
        Player(Player const &copy);
        ~Player(void);
        Player const &operator=(Player const &copy);

        const std::string &getName() const;
        bool               isAlive() const;
        t_uint             getScore() const;
        enum direction     getDirection() const;

        enum direction     setDirection(enum direction);
        void               eat(game_entity *entity);
        void               poop();
        void               die();

    private:
        const std::string        _name;
        std::list<game_entity *> _body;
        t_uint                   _score;
        enum direction           _direction;
};

#endif // PLAYER_HPP
