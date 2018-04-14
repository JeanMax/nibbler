/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlGlfw.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:39 by bmbarga           #+#    #+#             */
//   Updated: 2018/04/14 21:19:13 by mcanal           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "DlGlfw.class.hpp"
#include <iostream>

DlGlfw::DlGlfw(void):IDl(), win(NULL), area(NULL)
{
}

DlGlfw::~DlGlfw(void)
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

void		DlGlfw::print(enum game_entity **map, const unsigned int width, const unsigned int height)
{
	t_color		col;
	t_rect		r;
	bool		fill;

	if (!this->area)
	{
		if (!(this->area = glfw_create_bitmap(width * UNIT, height * UNIT)))
		{
			std::cout << "Error : texture area set to null" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	//clear background
	glfw_set_target_bitmap(glfw_get_backbuffer(this->win));
	col = g_col_white;
	glfw_clear_to_color(glfw_map_rgb(col.r, col.g, col.b));

	//set map area
	glfw_set_target_bitmap(this->area);
	col = g_col_black;
	glfw_clear_to_color(glfw_map_rgb(col.r, col.g, col.b));

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
					glfw_draw_filled_rectangle(r.x, r.y, r.w, r.h, glfw_map_rgb(col.r, col.g, col.b));
				else
					glfw_draw_rectangle(r.x, r.y, r.w, r.h, glfw_map_rgb(col.r, col.g, col.b), 1);
			}
		}
	}

	//
	glfw_set_target_bitmap(glfw_get_backbuffer(this->win));
	glfw_draw_bitmap(this->area, (MAX_WIDTH / 2 - width / 2) * UNIT, (MAX_HEIGHT / 2 - height / 2) * UNIT, 0);
	glfw_flip_display();
}

key			DlGlfw::keyEvent(void)
{
	key		e = KEY_NONE;

	if (glfw_is_event_queue_empty(this->e_queue))
		return (KEY_NONE);
	glfw_wait_for_event(this->e_queue, this->event);
	if (this->event->type == GLFW_EVENT_DISPLAY_CLOSE)
		return (KEY_EXIT);
	else if (this->event->type == GLFW_EVENT_KEY_DOWN)
	{
		switch (this->event->keyboard.keycode)
		{
			case GLFW_KEY_A:
				return (KEY_LEFT_A);
			case GLFW_KEY_S:
				return (KEY_RIGHT_A);
			case GLFW_KEY_G:
				return (KEY_LEFT_B);
			case GLFW_KEY_H:
				return (KEY_RIGHT_B);
			case GLFW_KEY_K:
				return (KEY_LEFT_C);
			case GLFW_KEY_L:
				return (KEY_RIGHT_C);
			case GLFW_KEY_LEFT:
				return (KEY_LEFT_D);
			case GLFW_KEY_RIGHT:
				return (KEY_RIGHT_D);

			case GLFW_KEY_1:
				return (KEY_LIB_A);
			case GLFW_KEY_2:
				return (KEY_LIB_B);
			case GLFW_KEY_3:
				return (KEY_LIB_C);

			case GLFW_KEY_ESCAPE:
				return (KEY_EXIT);
			default:
				break ;
		}
	}
	return e;
}

void			dl_close(IDl *dl)
{
	DlGlfw	*tmp;

	tmp = dynamic_cast<DlGlfw*>(dl);
	if (!dl)
	{
		std::cout << "Error : dl is set to null !"<< std::endl;
		exit(EXIT_FAILURE);
	}
	glfwDestroyWindow(tmp->win);
	glfwTerminate();
	delete (dl);
}

IDl				*dl_init(void)
{
	DlGlfw					*dl;

	if (!(dl = new DlGlfw()))
	{
		std::cout << "Error : dl" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!glfwInit())
	{
		std::cout << "Error : glfwInit" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!(dl->win = glfwCreateWindow(MAX_WIDTH * UNIT,
									 MAX_HEIGHT * UNIT,
									 "GLFW", NULL, NULL)))
	{
		std::cout << "Error : glfwCreateWindow" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetWindowTitle("GLFW");
	//TODO: center window?

	glfwMakeContextCurrent(window);

	return (dynamic_cast<IDl*>(dl));
}
