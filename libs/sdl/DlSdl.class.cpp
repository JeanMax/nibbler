/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSdl.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:58:17 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 19:58:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DlSdl.class.hpp"
#include <iostream>

DlSdl::DlSdl(void):IDl()
{
	std::cout << "DlSdl constructor called" << std::endl;//_DEBUG_//
}

DlSdl::~DlSdl(void)
{
	std::cout << "DlSdl destructor called" << std::endl;//_DEBUG_//
}

void		DlSdl::print(Map map) const
{
	(void)map;
	std::cout << "DlSdl I print map" << std::endl;//_DEBUG_//
}

e_key		DlSdl::keyEvent(void) const
{
	e_key	e;

	std::cout << "DlSdl keyEvent" << std::endl;//_DEBUG_//
	return e;
}
