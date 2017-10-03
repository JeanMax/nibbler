/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlAllegro.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:39 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/03 19:18:34 by bmbarga          ###   ########.fr       */
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

void		DlAllegro::print(Map const map)
{
	(void)map;
	std::cout << "DlAllegro I print map" << std::endl;//_DEBUG_//
}

key			DlAllegro::keyEvent(void)
{
	key		e = (key)-1;

	std::cout << "DlAllegro keyEvent" << std::endl;//_DEBUG_//
	return e;
}

void			dl_close(IDl *dl)
{
	std::cout << "I close DlAllegro" << std::endl;//_DEBUG_//
	delete (dl);
}

IDl				*dl_init(void)
{
	IDl			*dl;

	dl = dynamic_cast<IDl*>(new DlAllegro());
	if (!dl)
	{
		std::cout << "Error : dl" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (dl);
}
