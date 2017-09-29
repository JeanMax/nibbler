// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_dummy.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/29 15:31:46 by mc                #+#    #+#             //
//   Updated: 2017/09/29 16:22:16 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "test_nibbler.hpp"

void test_dummy()
{
    MU_ASSERT(42 == 21 + 21, "This is basic maths for a computer, really...");
    MU_ASSERT_FATAL(TRUE, "Damn! I was pretty sure of that one.");
}
