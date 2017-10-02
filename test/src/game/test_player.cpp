// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_player.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/01 00:15:26 by mc                #+#    #+#             //
//   Updated: 2017/10/02 21:17:05 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "test_nibbler.hpp"
#include "Player.hpp"

void test_player()
{
    Player *test_player = new Player();

    MU_ASSERT(test_player != NULL, "test is null :/");

    delete test_player;


    test_player = new Player("bob");

    MU_ASSERT(test_player != NULL, "test is null :/");
    MU_ASSERT(test_player->getName() == "bob", "you aren't bob! :O");

    delete test_player;
}
