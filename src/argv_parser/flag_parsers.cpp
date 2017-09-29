// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parse_argv.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 16:24:25 by mc                #+#    #+#             //
//   Updated: 2017/09/29 21:18:46 by mc               ###   ########.fr       //
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
    if (!*s || !only_digits(s)) {
        ERROR("error: '" << s << "': non numerical");
        return false;
    }

    g_parsed_args.width = atoi(s);

    if (g_parsed_args.width < MIN_WIDTH) {
        ERROR(
            "error: '" << g_parsed_args.width
            << "': under width limit (" << MIN_WIDTH << ")"
        );
        return false;
    }
    if (g_parsed_args.width > MAX_WIDTH) {
        ERROR(
            "error: '" << g_parsed_args.width
            << "': over width limit (" << MAX_WIDTH << ")"
        );
        return false;
    }

    return true;
}

bool        parse_height(const char *s)
{
    if (!*s || !only_digits(s)) {
        ERROR("error: '" << s << "': non numerical");
        return false;
    }

    g_parsed_args.height = atoi(s);

    if (g_parsed_args.height < MIN_HEIGHT) {
        ERROR(
            "error: '" << g_parsed_args.height
            << "': under height limit (" << MIN_HEIGHT << ")"
        );
        return false;
    }
    if (g_parsed_args.height > MAX_HEIGHT) {
        ERROR(
            "error: '" << g_parsed_args.height
            << "': over height limit (" << MAX_HEIGHT << ")"
        );
        return false;
    }

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
