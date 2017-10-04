// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_map.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 20:58:40 by mc                #+#    #+#             //
//   Updated: 2017/09/30 21:06:55 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "test_nibbler.hpp"
#include "Map.hpp"

void test_map()
{
    Map *test_map = new Map();

    MU_ASSERT(
        test_map->getWidth() == DEFAULT_WIDTH,
        "test (%d) and ctrl (%d) differ (input: %s)",
        test_map->getWidth(), DEFAULT_WIDTH, "none"
    );

    MU_ASSERT(
        test_map->getHeight() == DEFAULT_HEIGHT,
        "test (%d) and ctrl (%d) differ (input: %s)",
        test_map->getHeight(), DEFAULT_HEIGHT, "none"
    );

    MU_ASSERT(test_map->getArea() != NULL, "test is null :/");

    delete test_map;


    test_map = new Map(32, 32);

    MU_ASSERT(
        test_map->getWidth() == 32,
        "test (%d) and ctrl (%d) differ (input: %s)",
        test_map->getWidth(), 32, "none"
    );

    MU_ASSERT(
        test_map->getHeight() == 32,
        "test (%d) and ctrl (%d) differ (input: %s)",
        test_map->getHeight(), 32, "none"
    );

    MU_ASSERT(test_map->getArea() != NULL, "test is null :/");

    delete test_map;
}
