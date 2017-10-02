// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_game.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/02 21:33:29 by mc                #+#    #+#             //
//   Updated: 2017/10/02 21:47:11 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "test_nibbler.hpp"
#include "Game.hpp"

void test_game()
{
    const char *names[] = {"bob", NULL};
    Game *test_game = new Game(42, 42, names);

    MU_ASSERT(test_game != NULL, "test is null :/");
    MU_ASSERT(test_game->getPlayer(PLAYER_A).getName() == "bob", "you aren't bob! :O");
    MU_ASSERT(
        test_game->getMap().getWidth() == 42,
        "test (%d) and ctrl (%d) differ (input: %s)",
        test_game->getMap().getWidth(), 42, "none"
    );

    MU_ASSERT(
        test_game->getMap().getHeight() == 42,
        "test (%d) and ctrl (%d) differ (input: %s)",
        test_game->getMap().getHeight(), 42, "none"
    );

    MU_ASSERT(test_game->getMap().getArea() != NULL, "test is null :/");


    delete test_game;
}
