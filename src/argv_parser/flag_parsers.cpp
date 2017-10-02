// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parse_argv.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 16:24:25 by mc                #+#    #+#             //
//   Updated: 2017/10/02 19:32:22 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*
** helper functions used by parse_flag() in parse_argv.cpp
*/

#include "argv_parser.hpp"

static bool only_digits(const char *s)
{
    if (!*s) {
        return true;
    }
    if (!isdigit(*s)) {
        return false;
    }

    return only_digits(s + 1);
}

bool        parse_width(const char *s)
{
    int w;

    if (!*s || !only_digits(s)) {
        ERROR("error: '" << s << "': non numerical");
        return false;
    }

    w = atoi(s);

    if (w < MIN_WIDTH) {
        ERROR(
            "error: '" << w
            << "': under width limit (" << MIN_WIDTH << ")"
        );
        return false;
    }
    if (w > MAX_WIDTH) {
        ERROR(
            "error: '" << w
            << "': over width limit (" << MAX_WIDTH << ")"
        );
        return false;
    }

    g_parsed_args.width = static_cast<t_uint>(w);

    return true;
}

bool        parse_height(const char *s)
{
    int h;

    if (!*s || !only_digits(s)) {
        ERROR("error: '" << s << "': non numerical");
        return false;
    }

    h = atoi(s);

    if (h < MIN_HEIGHT) {
        ERROR(
            "error: '" << h
            << "': under height limit (" << MIN_HEIGHT << ")"
        );
        return false;
    }
    if (h > MAX_HEIGHT) {
        ERROR(
            "error: '" << h
            << "': over height limit (" << MAX_HEIGHT << ")"
        );
        return false;
    }

    g_parsed_args.height = static_cast<t_uint>(h);

    return true;
}

bool        parse_library(const char *s)
{
    const char *libs[] = {
        LIB_NAME_A,
        LIB_NAME_B,
        LIB_NAME_C,
    };
    int i;

    for (i = 0; i < NUMBER_OF_LIBS; i++) {
        if (!strcmp(s, libs[i])) {
            g_parsed_args.lib = static_cast<enum lib>(i);
            return true;
        }
    }

    ERROR(
        "error: '" << s
        << "': library not found (available: " << AVAILABLE_LIB_NAMES << ")"
     );
    return false;
}
