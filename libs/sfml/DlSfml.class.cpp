/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSfml.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:03:03 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/02 18:53:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DlSfml.class.hpp"
#include <iostream>

DlSfml::DlSfml(void):IDl()
{
	std::cout << "DlSfml constructor called" << std::endl;//_DEBUG_//
}

DlSfml::~DlSfml(void)
{
	std::cout << "DlSfml destructor called" << std::endl;//_DEBUG_//
}

void		DlSfml::print(Map map) const
{
	(void)map;
	std::cout << "DlSfml I print map" << std::endl;//_DEBUG_//
}

e_key		DlSfml::keyEvent(void) const
{
	e_key	e;

	std::cout << "DlSfml keyEvent" << std::endl;//_DEBUG_//
	return e;
}

void			dl_close(IDl *dl)
{
	std::cout << "I close DlSfml" << std::endl;//_DEBUG_//
	delete (dl);
}

IDl				*dl_init(void)
{
	IDl			*dl;

	dl = dynamic_cast<IDl*>(new DlSfml());
	if (!dl)
	{
		std::cout << "Error : dl" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (dl);
}
