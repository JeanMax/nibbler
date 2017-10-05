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
}

DlSdl::~DlSdl(void)
{
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

static void		setDrawColor(SDL_Renderer *ren, t_color col)
{
	SDL_SetRenderDrawColor(ren, col.r, col.g, col.b, col.a);
}

void		DlSdl::print(enum game_entity **map,
							const unsigned int width,
							const unsigned int height)
{
	SDL_Rect		r;
	t_color			col;
	bool			fill;

	col = g_col_black;
	if (!this->area)
	{
		if (!(this->area = SDL_CreateTexture(this->ren,
												SDL_PIXELFORMAT_RGBA8888,
												SDL_TEXTUREACCESS_TARGET,
												width * UNIT, height * UNIT)))
		{
			std::cout << "Error : texture area set to null" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	//clear background
	setDrawColor(this->ren, g_col_white);
	SDL_RenderClear(this->ren);

	//set map area
	SDL_SetRenderTarget(this->ren, this->area);
	setDrawColor(this->ren, g_col_black);
	SDL_RenderClear(this->ren);

	//display map area
	for (int i = 0; map[i]; i++)
	{
		for (int j = 0; map[i][j]; j++)
		{
			fill = true;
			setRect(&r, j * UNIT, i  * UNIT, (UNIT - 1), (UNIT - 1));
			if (map[i][j] != EMPTY)
			{
				if (map[i][j] == FOOD)
				{
					col = g_col_white;
					fill = false;
				}
				else if (map[i][j] == BONUS)
				{
					col = g_col_bonus;
				}
				else if (map[i][j] == INNER_WALL)
				{
					col = g_col_white;
				}
				else
				{
					if (map[i][j] == SNAKE_A
						|| map[i][j] == HEAD_A)
						col = g_col_pa;
					else if (map[i][j] == SNAKE_B
						|| map[i][j] == HEAD_B)
						col = g_col_pb;
					else if (map[i][j] == SNAKE_C
						|| map[i][j] == HEAD_C)
						col = g_col_pc;
					else if (map[i][j] == SNAKE_D
						|| map[i][j] == HEAD_D)
						col = g_col_pd;
					if (map[i][j] < 'a')
					{
						setRect(&r, j * UNIT, i  * UNIT, (UNIT), (UNIT));
						fill = false;
					}
				}
				setDrawColor(this->ren, col);
				if (fill)
					SDL_RenderFillRect(this->ren, &r);
				else
					SDL_RenderDrawRect(this->ren, &r);
			}
		}
	}

	SDL_SetRenderTarget(this->ren, NULL);

	//place map texture to window
	setRect(&r, (MAX_WIDTH / 2 - width / 2) * UNIT,
				(MAX_HEIGHT / 2 - height / 2)  * UNIT, 0, 0);
	SDL_QueryTexture(this->area, NULL, NULL, &r.w, &r.h);
	SDL_RenderCopy(this->ren, this->area, NULL, &r);
	SDL_RenderPresent(this->ren);
}

key			DlSdl::keyEvent(void)
{
	key		e = KEY_NONE;

	if (!SDL_PollEvent(this->event))
		return (KEY_NONE);
	if (this->event->type == SDL_QUIT)
		return (KEY_EXIT);
	else if (this->event->type == SDL_KEYDOWN
				&& !this->event->key.repeat)
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
	dl->win = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											MAX_WIDTH * UNIT,
											MAX_HEIGHT * UNIT,
											SDL_WINDOW_SHOWN);
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
	//disable key repeat
	return (dynamic_cast<IDl*>(dl));
}
