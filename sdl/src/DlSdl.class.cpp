/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSdl.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:58:17 by bmbarga           #+#    #+#             */
//   Updated: 2017/10/03 22:05:21 by mc               ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "DlSdl.class.hpp"
#include <iostream>
#include <unistd.h>

DlSdl::DlSdl(void) : IDl(), win(NULL), ren(NULL),
						event(NULL), area(NULL)
{
	std::cout << "DlSdl constructor called" << std::endl;//_DEBUG_//
}

DlSdl::~DlSdl(void)
{
	std::cout << "DlSdl destructor called" << std::endl;//_DEBUG_//
}

static void	setRect(SDL_Rect *r, int x, int y, int w, int h)
{
	if (!r)
		return ;
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;
}

void		DlSdl::print(Map const map)
{
	SDL_Rect		r;
	game_entity		**m;

	if (!(m = map.getArea()))
	{
		std::cout << "Error : map area set to null" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!this->area)
	{
		if (!(this->area = SDL_CreateTexture(this->ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, map.getWidth() * UNIT, map.getHeight() * UNIT)))
		{
			std::cout << "Error : texture area set to null" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	//clear background
	SDL_SetRenderDrawColor(this->ren, 0, 0, 0, 255);
	SDL_RenderClear(this->ren);

	//set map area
	SDL_SetRenderTarget(this->ren, this->area);
	SDL_SetRenderDrawColor(this->ren, 0, 0, 0, 255);
	SDL_RenderClear(this->ren);

	//display map area
	for (int i = 0; m[i]; i++)
	{
		for (int j = 0; m[i][j]; j++)
		{
			if (m[i][j] != EMPTY)
			{
				setRect(&r, j * UNIT, i  * UNIT, UNIT, UNIT);

				//set color according to m[i][j] value
				SDL_SetRenderDrawColor(this->ren, 0, 0, 0, 255);

				//fill rect
				SDL_RenderFillRect(this->ren, &r);

				//reset color
				SDL_SetRenderDrawColor(this->ren, 0, 0, 0, 255);
			}
		}
	}

	SDL_SetRenderTarget(this->ren, NULL);

	//place map texture to window
	setRect(&r, (MAX_WIDTH / 2 - map.getWidth() / 2)  * UNIT, (MAX_HEIGHT / 2 - map.getHeight() / 2)  * UNIT, 0, 0);
	SDL_QueryTexture(this->area, NULL, NULL, &r.w, &r.h);
	SDL_RenderCopy(this->ren, this->area, NULL, &r);
	SDL_RenderPresent(this->ren);
}

key			DlSdl::keyEvent(void)
{
	key		e = (key)-1;

	SDL_PollEvent(this->event);
	if (this->event->type == SDL_QUIT)
		return (KEY_EXIT);
	else if (this->event->type == SDL_KEYDOWN)
	{
		switch (this->event->key.keysym.sym)
		{
			case SDLK_a:
				return (KEY_LEFT_A);
			case SDLK_s:
				return (KEY_RIGHT_A);
			case SDLK_g:
				return (KEY_LEFT_B);
			case SDLK_h:
				return (KEY_RIGHT_B);
			case SDLK_k:
				return (KEY_LEFT_C);
			case SDLK_l:
				return (KEY_RIGHT_C);
			case SDLK_LEFT:
				return (KEY_LEFT_D);
			case SDLK_RIGHT:
				return (KEY_RIGHT_D);

			case SDLK_1:
				return (KEY_LIB_A);
			case SDLK_2:
				return (KEY_LIB_B);
			case SDLK_3:
				return (KEY_LIB_C);

			case SDLK_ESCAPE:
				return (KEY_EXIT);
			default:
				break ;
		}
	}
	return (e);
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
	delete (tmp->event);
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
	dl->win = SDL_CreateWindow("zboob SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAX_WIDTH * UNIT, MAX_HEIGHT * UNIT, SDL_WINDOW_SHOWN);
	if (!dl->win)
	{
		std::cout << "Error dl->win set to null" << std::endl;
		exit(EXIT_FAILURE);
	}
	dl->ren = SDL_CreateRenderer(dl->win, -1, SDL_RENDERER_ACCELERATED);
	if (!dl->ren)
	{
		std::cout << "Error dl->ren set to null" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!(dl->event = new SDL_Event))
	{
		std::cout << "Error dl->event set to null" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (dl);
}
