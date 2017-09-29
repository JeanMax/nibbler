// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parse_argv.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 16:24:25 by mc                #+#    #+#             //
//   Updated: 2017/09/29 19:06:58 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "argv_parser.hpp"

static bool only_digits(const char *s)
{
    while (*s) {
        if (!isdigit(*s))
            return false;
        s++;
    }
    return true;
}

bool        parse_width(const char *s)
{
    if (!only_digits(s)) {
        return false; //TODO: specific error msg
    }

    g_parsed_args.width = atoi(s);
    if (g_parsed_args.width < MIN_WIDTH || g_parsed_args.width > MAX_WIDTH) {
        return false; //TODO: specific error msg
    }

    return true;
}

bool        parse_height(const char *s)
{
    if (!only_digits(s)) {
        return false; //TODO: specific error msg
    }

    g_parsed_args.height = atoi(s);
    if (g_parsed_args.height < MIN_HEIGHT || g_parsed_args.height > MAX_HEIGHT) {
        return false; //TODO: specific error msg
    }

    return true;
}

bool        parse_library(const char *s)
{
    const char *libs[] = {
        LIB_NAME_A, LIB_NAME_B, LIB_NAME_C,
    };
    int i;

    for (i = 0; i < NUMBER_OF_LIBS; i++) {
        if (!strcmp(s, libs[i])) {
            g_parsed_args.lib = static_cast<enum lib>(i);
            return true;
        }
    }

    return false; //TODO: specific error msg
}
