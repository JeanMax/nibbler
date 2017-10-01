/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlAllegro.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:39 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 20:06:58 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DlAllegro.class.hpp"
#include <iostream>

DlAllegro::DlAllegro(void):IDl()
{
	std::cout << "DlAllegro constructor called" << std::endl;//_DEBUG_//
}

DlAllegro::~DlAllegro(void)
{
	std::cout << "DlAllegro destructor called" << std::endl;//_DEBUG_//
}

void		DlAllegro::print(Map map) const
{
	(void)map;
	std::cout << "DlAllegro I print map" << std::endl;//_DEBUG_//
}

e_key		DlAllegro::keyEvent(void) const
{
	e_key	e;

	std::cout << "DlAllegro keyEvent" << std::endl;//_DEBUG_//
	return e;
}
