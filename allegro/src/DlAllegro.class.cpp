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

DlAllegro::DlAllegro(void):IDl(), win(NULL), e_queue(NULL), event(NULL), area(NULL)
{
}

DlAllegro::~DlAllegro(void)
{
}

static void	setRect(t_rect *r, int x, int y, int w, int h)
{
	if (!r)
		return ;
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;
}

void		DlAllegro::print(enum game_entity **map, const unsigned int width, const unsigned int height)
{
	t_color		col;
	t_rect		r;
	bool		fill;

	if (!this->area)
	{
		if (!(this->area = al_create_bitmap(width * UNIT, height * UNIT)))
		{
			std::cout << "Error : texture area set to null" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	//clear background
	al_set_target_bitmap(al_get_backbuffer(this->win));
	col = g_col_white;
	al_clear_to_color(al_map_rgb(col.r, col.g, col.b));

	//set map area
	al_set_target_bitmap(this->area);
	col = g_col_black;
	al_clear_to_color(al_map_rgb(col.r, col.g, col.b));

	//display map area
	for (int i = 0; map[i]; i++)
	{
		for (int j = 0; map[i][j]; j++)
		{
			fill = true;
			setRect(&r, j * UNIT, i  * UNIT, j * UNIT + (UNIT - 1), i * UNIT + (UNIT - 1));
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
						setRect(&r, j * UNIT, i  * UNIT, j * UNIT + (UNIT), i * UNIT + (UNIT));
						fill = false;
					}
				}
				if (fill)
					al_draw_filled_rectangle(r.x, r.y, r.w, r.h, al_map_rgb(col.r, col.g, col.b));
				else
					al_draw_rectangle(r.x, r.y, r.w, r.h, al_map_rgb(col.r, col.g, col.b), 1);
			}
		}
	}

	//
	al_set_target_bitmap(al_get_backbuffer(this->win));
	al_draw_bitmap(this->area, (MAX_WIDTH / 2 - width / 2) * UNIT, (MAX_HEIGHT / 2 - height / 2) * UNIT, 0);
	al_flip_display();
}

key			DlAllegro::keyEvent(void)
{
	key		e = KEY_NONE;

	if (al_is_event_queue_empty(this->e_queue))
		return (KEY_NONE);
	al_wait_for_event(this->e_queue, this->event);
	if (this->event->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		return (KEY_EXIT);
	else if (this->event->type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (this->event->keyboard.keycode)
		{
			case ALLEGRO_KEY_A:
				return (KEY_LEFT_A);
			case ALLEGRO_KEY_S:
				return (KEY_RIGHT_A);
			case ALLEGRO_KEY_G:
				return (KEY_LEFT_B);
			case ALLEGRO_KEY_H:
				return (KEY_RIGHT_B);
			case ALLEGRO_KEY_K:
				return (KEY_LEFT_C);
			case ALLEGRO_KEY_L:
				return (KEY_RIGHT_C);
			case ALLEGRO_KEY_LEFT:
				return (KEY_LEFT_D);
			case ALLEGRO_KEY_RIGHT:
				return (KEY_RIGHT_D);

			case ALLEGRO_KEY_1:
				return (KEY_LIB_A);
			case ALLEGRO_KEY_2:
				return (KEY_LIB_B);
			case ALLEGRO_KEY_3:
				return (KEY_LIB_C);

			case ALLEGRO_KEY_ESCAPE:
				return (KEY_EXIT);
			default:
				break ;
		}
	}
	return e;
}

void			dl_close(IDl *dl)
{
	DlAllegro	*tmp;

	tmp = dynamic_cast<DlAllegro*>(dl);
	if (!dl)
	{
		std::cout << "Error : dl is set to null !"<< std::endl;
		exit(EXIT_FAILURE);
	}
	al_destroy_bitmap(tmp->area);
	al_destroy_event_queue(tmp->e_queue);
	al_destroy_display(tmp->win);
	delete(tmp->event);
	delete (dl);
}

IDl				*dl_init(void)
{
	DlAllegro					*dl;
	ALLEGRO_MONITOR_INFO		info;

	if (!(dl = new DlAllegro()))
	{
		std::cout << "Error : dl" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!al_init())
	{
		std::cout << "Error : al_init" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!(dl->win = al_create_display(MAX_WIDTH * UNIT,
										MAX_HEIGHT * UNIT)))
	{
		std::cout << "Error : al_create_display" << std::endl;
		exit(EXIT_FAILURE);
	}

	al_set_window_title(dl->win, "ALLEGRO");

	//center window
	al_get_monitor_info(0, &info);
	al_set_window_position(dl->win, (info.x2 - info.x1) / 2 - MAX_WIDTH * UNIT / 2, (info.y2 - info.y1) / 2 - MAX_HEIGHT * UNIT / 2);

	//event queue
	if (!(dl->e_queue = al_create_event_queue()))
	{
		std::cout << "Error : al_create_event_queue" << std::endl;
		exit(EXIT_FAILURE);
	};

	if(!al_install_keyboard())
	{
		std::cout << "Error : al_install_keyboard" << std::endl;
		exit(EXIT_FAILURE);
	}
	//register event type
	al_register_event_source(dl->e_queue, al_get_display_event_source(dl->win));
	al_register_event_source(dl->e_queue, al_get_keyboard_event_source());

	if (!(dl->event = new ALLEGRO_EVENT))
	{
		std::cout << "Error : new ALLEGRO_EVENT" << std::endl;
		exit(EXIT_FAILURE);

	}
	return (dynamic_cast<IDl*>(dl));
}
