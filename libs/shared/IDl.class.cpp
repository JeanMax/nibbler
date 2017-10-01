/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDl.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:08:55 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 20:00:46 by bmbarga          ###   ########.fr       */
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

void			close(IDl *dl)
{
	std::cout << "I close IDl" << std::endl;//_DEBUG_//
	delete (dl);
}

IDl				*init(e_type e)
{
	IDl			*dl;

	dl = NULL;
	switch (e)
	{
		case T_SDL:
			dl = dynamic_cast<IDl*>(new DlSdl());
			break;
		case T_SFML:
			dl = dynamic_cast<IDl*>(new DlSfml());
			break;
		case T_ALLEGRO:
			dl = dynamic_cast<IDl*>(new DlAllegro());
			break;
		default:
			std::cout << "type unknown" << std::endl;
			break;
	}
	if (!dl)
	{
		std::cout << "Error : dl" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (dl);
}
