/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSdl.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:58:17 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/02 19:06:13 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DlSdl.class.hpp"
#include <iostream>
#include <unistd.h>

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

	SDL_PollEvent(this->event);
	std::cout << "DlSdl keyEvent" << std::endl;//_DEBUG_//
	return e;
}

void			dl_close(IDl *dl)
{
	DlSdl				*tmp;

	if (!(tmp = dynamic_cast<DlSdl*>(dl)))
	{
		std::cout << "Error : dl is set to null !"<< std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "I close DlSdl" << std::endl;//_DEBUG_//
	delete (dl->event);
	SDL_DestroyWindow(tmp->win);
	SDL_Quit();
	delete (dl);
}

IDl				*dl_init(void)
{
	DlSdl				*dl;

	if (!(dl = new DlSdl()))
	{
		std::cout << "Error : dl" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error SDL_Init() : " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
	dl->win = SDL_CreateWindow("zboob SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (!dl->win)
	{
		std::cout << "Error dl->win set to null" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!(dl->event = new SDL_Event))
	{
		std::cout << "Error dl->event set to null" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (dl);
}
