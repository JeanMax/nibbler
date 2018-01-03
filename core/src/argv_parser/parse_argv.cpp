// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parse_argv.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 16:24:25 by mc                #+#    #+#             //
//   Updated: 2018/01/03 21:25:48 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "argv_parser.hpp"

t_args g_parsed_args = {
    DEFAULT_WIDTH,
    DEFAULT_HEIGHT,
    DEFAULT_LIB,
    NULL,
    {0},
};


static bool usage_msg(bool verbose)
{
    if (!verbose) {
        ERROR(
            "usage: " << g_parsed_args.bin_name
                << " [--help] [-w] [-h] [-l] [-p]"
        );
        return false;
    }

    MSG(
        "usage: " << g_parsed_args.bin_name
            << " [--help] [-w] [-h] [-l] [-p]" << std::endl
        << std::endl
        << "optional arguments:" << std::endl
        << "  --help               show this help message and exit" << std::endl
        << "  -w, --width=NUM      specify the game area width "
           "(default: " << DEFAULT_WIDTH << ")" << std::endl
        << "  -h, --height=NUM     specify the game area height "
           "(default: " << DEFAULT_HEIGHT << ")" << std::endl
        << "  -l, --library=STR    choose a graphical library "
           "(default: " DEFAULT_LIB_NAME
           " - available: " AVAILABLE_LIB_NAMES ")" << std::endl
        << "  -p, --player=STR     specify player name "
           "(default: " DEFAULT_PLAYER_NAME ") " << std::endl
        << "                       repeat to indicate mutiples players "
           "(max: " << MAX_PLAYERS << " - default: 1)"
    );
    return false;
}

static bool parse_flag(const char *s)
{
    const char *flags[] = {
        "--width=", "--height=", "--library=", "--player=",
        "-w=",      "-h=",       "-l=",        "-p=",
    };
    bool (*flag_parser[NUMBER_OF_FLAGS])(const char *s) = {
        parse_width, parse_height, parse_library, parse_player_name,
    };
    int    i;
    size_t len;

    for (i = 0; i < NUMBER_OF_FLAGS * 2; i++) {
        len = strlen(flags[i]);
        if (!strncmp(s, flags[i], len)) {
            return flag_parser[i % NUMBER_OF_FLAGS](s + len);
        }
    }

    ERROR("error: '" << s << "': invalid option");
    return false;
}


/**
** parse command-line argument and fill the global struct 'g_parsed_args'
** @param av  the argument to parse
** @return    false if something went wrong
*/
bool        parse_argv(const char **av)
{
    if (!*av) {
        if (!*g_parsed_args.players_names) {
            *g_parsed_args.players_names = DEFAULT_PLAYER_NAME;
        }
        return !!g_parsed_args.bin_name;
    }

    if (!g_parsed_args.bin_name) {
        g_parsed_args.bin_name = *av;
    } else if (!strcmp(*av, "--help")) {
        return usage_msg(true);
    } else if (!parse_flag(*av)) {
        return usage_msg(false);
    }

    return parse_argv(av + 1);
}
