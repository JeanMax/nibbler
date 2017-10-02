// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/01 00:36:59 by mc                #+#    #+#             //
//   Updated: 2017/10/02 14:50:26 by mc               ###   ########.fr       //
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

        void       nextFrame();
        void       sleepFrame() const;
        void       handleEvent(enum direction direction, enum player player);
        bool       isOver() const;

        const Map     &getMap() const;
        const Player  &getPlayer(enum player player) const;
        t_uint         getNumberOfPlayers() const;


    private:
        bool           _allocPlayers(const char **players_names);

        Map            _map;
        Player       **_players;
        t_uint         _number_of_players;
};

#endif // GAME_HPP
