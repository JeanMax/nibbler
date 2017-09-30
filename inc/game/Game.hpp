// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/01 00:36:59 by mc                #+#    #+#             //
//   Updated: 2017/10/01 01:55:00 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "game_util.hpp"
# include "Map.hpp"
# include "Player.hpp"

class Game {
    public:
        Game(
            const t_uint width = DEFAULT_WIDTH,
            const t_uint height = DEFAULT_HEIGHT,
            const char **players_names = NULL
        );
        Game(Game const &copy);
        ~Game(void);
        Game const &operator=(Game const &copy);

        bool       nextFrame();
        void       sleepFrame();
        void       handleEvent(enum direction direction, enum player player);

        const Map     &getMap() const;
        const Player  &getPlayer(enum player player) const;
        Player       **getPlayers() const;
        t_uint         getNumberOfPlayers() const;
        bool           isOver() const;


    private:
        bool           _allocPlayers(const char **players_names);

        Map            _map;
        Player       **_players;
        t_uint         _number_of_players;
};

#endif // GAME_HPP
