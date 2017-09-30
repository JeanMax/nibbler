// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_player.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/01 00:15:26 by mc                #+#    #+#             //
//   Updated: 2017/10/01 00:23:38 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "test_nibbler.hpp"
#include "Player.hpp"

void test_player()
{
    Player *test_player = new Player();

    MU_ASSERT(test_player != NULL, "test is null :/");
    MU_ASSERT(test_player->getScore() == 0, "uh?");
    test_player->eat(NULL);
    test_player->poop();

    delete test_player;


    test_player = new Player("bob");

    MU_ASSERT(test_player != NULL, "test is null :/");
    MU_ASSERT(test_player->getName() == "bob", "you aren't bob! :O");
    test_player->die();

    delete test_player;
}
