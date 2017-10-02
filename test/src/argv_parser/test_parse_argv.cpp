// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_parse_argv.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 15:31:46 by mc                #+#    #+#             //
//   Updated: 2017/10/03 00:37:34 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "test_nibbler.hpp"
#include "argv_parser.hpp"

#define NUMBER_OF_INPUTS 10
#define MAX_ARGS 42

#define STUPID_SIZE 1024
char stupid_buffer[STUPID_SIZE];

static void reset_args()
{
    g_parsed_args = {
        DEFAULT_WIDTH,
        DEFAULT_HEIGHT,
        DEFAULT_LIB,
        NULL,
        {0}
    };
}

static void input_to_buffer(const char **av)
{
    char *s = stupid_buffer;
    bzero((void *)s, STUPID_SIZE);

    *s++ = '{';
    *s++ = ' ';
    while (*av) {
        strcpy(s, *av);
        s += strlen(*av);
        *s++ = ' ';
        av++;
    }
    *s = '}';
}

static void check_arg_struct(const t_args *ctrl)
{
    MU_ASSERT(
        g_parsed_args.width == ctrl->width,
        "test (%d) and ctrl (%d) differ (input: %s)",
        g_parsed_args.width, ctrl->width, stupid_buffer
    );

    MU_ASSERT(
        g_parsed_args.height == ctrl->height,
        "test (%d) and ctrl (%d) differ (input: %s)",
        g_parsed_args.height, ctrl->height, stupid_buffer
    );

    MU_ASSERT(
        g_parsed_args.lib == ctrl->lib,
        "test (%d) and ctrl (%d) differ (input: %s)",
        g_parsed_args.lib, ctrl->lib, stupid_buffer
    );
}

void test_parse_argv()
{
    const char *inputs[NUMBER_OF_INPUTS][MAX_ARGS] = {
        {"./test1", NULL},
        {"./test2", "--help", NULL},
        {"./test3", "ezzegzeg", NULL},
        {"./test4", "-w=", NULL},
        {"./test5", "-h=", NULL},
        {"./test6", "-l=", NULL},
        {"./test7", "-w=42", NULL},
        {"./test8", "-h=42", NULL},
        {"./test9", "-l=sdl", NULL},
        {"./test10", "--width=42", "--height=42", "-l=sdl", NULL},
    };
    const bool results[NUMBER_OF_INPUTS] = {
        true,
        true,
        false,
        false,
        false,
        false,
        true,
        true,
        true,
        true,
    };
    const t_args parsed_args[NUMBER_OF_INPUTS] = {
        {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_LIB, NULL, {0}},
        {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_LIB, NULL, {0}},
        {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_LIB, NULL, {0}},
        {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_LIB, NULL, {0}},
        {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_LIB, NULL, {0}},
        {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_LIB, NULL, {0}},
        {42, DEFAULT_HEIGHT, DEFAULT_LIB, NULL, {0}},
        {DEFAULT_WIDTH, 42, DEFAULT_LIB, NULL, {0}},
        {DEFAULT_WIDTH, DEFAULT_HEIGHT, LIB_A, NULL, {0}},
        {42, 42, LIB_A, NULL, {0}},
    };
    bool test;


    for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
        input_to_buffer(inputs[i]);

        // ushhh
        std::cout.setstate(std::ios_base::badbit);
        std::cerr.setstate(std::ios_base::badbit);

        test = parse_argv(inputs[i]);

        std::cout.clear();
        std::cerr.clear();

        MU_ASSERT(
            test == results[i],
            "test (%d) and ctrl (%d) differ (input: %s)",
            !results[i], results[i], stupid_buffer
        );
        check_arg_struct(&parsed_args[i]);

        reset_args();
    }
}
