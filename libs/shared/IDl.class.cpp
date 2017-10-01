/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDl.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:08:55 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 21:20:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IDl.class.hpp"
#include "DlSdl.class.hpp"
#include "DlSfml.class.hpp"
#include "DlAllegro.class.hpp"

IDl::IDl(void)
{
	std::cout << "IDl constructor called" << std::endl;//_DEBUG_//
}

IDl::~IDl(void)
{
	std::cout << "IDl destructor called" << std::endl;//_DEBUG_//
}

