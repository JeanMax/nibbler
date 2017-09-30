/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nibbler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:28:01 by mc                #+#    #+#             */
//   Updated: 2017/10/01 00:16:23 by mc               ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_NIBBLER
# define TEST_NIBBLER

# include "minunit.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>


/*
** argv_parser
*/
void test_parse_argv(void);


/*
** game
*/
void test_map(void);
void test_player(void);


#endif // TEST_NIBBLER
