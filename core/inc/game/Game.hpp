// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/01 00:36:59 by mc                #+#    #+#             //
//   Updated: 2017/10/04 18:41:03 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

# include "game_util.hpp"
# include "Map.hpp"
# include "Player.hpp"
# include <ctime>
# include <unistd.h> //usleep

# define MAX_FPS     100.

# define DEFAULT_FPS 5.
# define INCREASE_FPS_SECONDS_INTERVAL 30
# define FPS_INCREASE 0.2

# define FPS_TO_US(fps) (1e6 / fps)


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
        void       sleepFrame();
        void       handleEvent(enum key key);
        bool       isOver() const;

        const Map     &getMap() const;
        const Player  &getPlayer(enum player player) const;
        t_uint         getNumberOfPlayers() const;
        t_uint         getFps() const;
        t_uint         getEllapsedSeconds() const;

    private:
        t_uint         _increaseFps();
        bool           _allocPlayers(const char **players_names);
        void           _freePlayers();

        Map            _map;
        Player       **_players;
        t_uint         _number_of_players;
        double         _fps;
        time_t         _tick;
        const time_t   _start_time;
        game_entity    *_bonus;
};

#endif // GAME_HPP
