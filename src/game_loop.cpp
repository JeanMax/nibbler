// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game_loop.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/02 19:04:44 by mc                #+#    #+#             //
//   Updated: 2017/10/02 21:09:54 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "nibbler.hpp"
#include "Game.hpp"

static bool        game_loop(Game &game)
{
    DEBUG_MAP(game.getMap());

    if (game.isOver()) {
        return true;
    }

    //lib.print(game.getMap()); // TODO: this...
    //game.print(lib.print_function) // TODO: ...or this?

    // enum key key = lib.getEvent(); //TODO
    // game.handleEvent(key);

    game.nextFrame();
    game.sleepFrame();

    return game_loop(game);
}

bool launch_game(const t_uint width, const t_uint height)
{
    const char *players_names[5] = { //TODO: parse names from argv or something
        "player1",
        "player2",
        "player3",
        "player4",
        NULL
    };
    Game game = Game(width, height, players_names);

    return game_loop(game);
}
