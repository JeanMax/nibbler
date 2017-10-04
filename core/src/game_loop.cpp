// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game_loop.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/02 19:04:44 by mc                #+#    #+#             //
//   Updated: 2017/10/04 17:24:52 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "nibbler.hpp"
#include "Game.hpp"

static bool        game_loop(Game &game)
{
    enum key	key;

    DEBUG_MAP(game.getMap());

	while ((key = g_dl.lib->keyEvent()) != KEY_NONE)
	{
		if (key == KEY_EXIT)
			return true;
    	game.handleEvent(key);
	}

    game.nextFrame();

    g_dl.lib->print(game.getMap().getArea(),
					game.getMap().getWidth(),
					game.getMap().getHeight());

    game.sleepFrame();

    return game.isOver() ? true : game_loop(game);
}

bool launch_game(const t_uint width,
                 const t_uint height,
                 const char **players_names)
{
    Game game = Game(width, height, players_names);

    return game_loop(game);
}
