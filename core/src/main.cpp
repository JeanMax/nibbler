// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 14:34:19 by mc                #+#    #+#             //
//   Updated: 2017/10/04 18:12:06 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*
** just a main... this is important to keep this file the lightest possible,
** because it won't be linked in the test executable
*/

#include "nibbler.hpp"


int             main(int unused, const char **av)
{
    (void)unused;

    if (!parse_argv(av)
		|| !load_dl(g_parsed_args.lib)) {
        return EXIT_FAILURE;
    }

    if (!launch_game(g_parsed_args.width, g_parsed_args.height, g_parsed_args.players_names)) {
        return EXIT_FAILURE;
    }

	close_dl();

    return EXIT_SUCCESS;
}
