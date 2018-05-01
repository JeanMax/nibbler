/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlGlfw.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:39 by bmbarga           #+#    #+#             */
//   Updated: 2018/04/27 20:06:53 by mcanal           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "DlGlfw.class.hpp"
#include <iostream>

DlGlfw::DlGlfw(void):IDl(), win(NULL)
{
}

DlGlfw::~DlGlfw(void)
{
}

void error_callback(int error, const char* description)
{
	(void)error;
	std::cerr << description << std::endl;
}

static void drawRect(t_rect *r)
{
	glBegin(GL_QUADS);
	glVertex2i(r->x, r->y);
	glVertex2i(r->x + r->w, r->y);
	glVertex2i(r->x + r->w, r->y + r->h);
	glVertex2i(r->x, r->y + r->h);
	glEnd();
}

static void	setRect(t_rect *r, int x, int y, int w, int h)
{
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;
}

void		DlGlfw::print(enum game_entity **map, const unsigned int width, const unsigned int height)
{
	t_rect		r;
	bool		fill;

	(void)width;				// DEBUG
	(void)height;				// DEBUG
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// DEBUG
	glColor4i(255, 0, 0, 127);
	setRect(
		&r,
		0, 0,
		50, 50
	);

	if (glGetError() != GL_NO_ERROR)
		std::cerr << "ABORT!!" << std::endl;
	glfwPollEvents();
	glfwSwapBuffers(this->win);
	return;
	// DEBUG


	//set map area
	// glfw_set_target_bitmap(this->area);
	// col = g_col_black;
	// glfw_clear_to_color(glfw_map_rgb(col.r, col.g, col.b));

	//display map area
	for (int i = 0; map[i]; i++)
	{
		for (int j = 0; map[i][j]; j++)
		{
			setRect(
				&r,
				j * UNIT, i  * UNIT,
				UNIT - 1, UNIT - 1
			);
			fill = true;
			glColor3i(map[i][j] == INNER_WALL ? WHITE : BLACK);

			switch (map[i][j]) {
			case FOOD:
				fill = false;
				break;
			case BONUS:
				glColor3i(MAGENTA);
				break;
			case INNER_WALL:
			case OUTER_WALL:
				r.w--;
				r.h--;
				fill = false;
				break;
			case SNAKE_A:
			case HEAD_A:
				glColor3i(RED);
				break;
			case SNAKE_B:
			case HEAD_B:
				glColor3i(GREEN);
				break;
			case SNAKE_C:
			case HEAD_C:
				glColor3i(BLUE);
				break;
			case SNAKE_D:
			case HEAD_D:
				glColor3i(YELLOW);
				break;
			default:
				;
			}
			drawRect(&r);
		}

		// if (fill)
		// 	glfw_draw_filled_rectangle(r.x, r.y, r.w, r.h, glfw_map_rgb(col.r, col.g, col.b));
		// else
		// 	glfw_draw_rectangle(r.x, r.y, r.w, r.h, glfw_map_rgb(col.r, col.g, col.b), 1);

	}

	// glFlush();
	glfwSwapBuffers(this->win);

	if (glGetError() != GL_NO_ERROR)
		std::cerr << "ABORT!!" << std::endl;

	// glfw_set_target_bitmap(glfw_get_backbuffer(this->win));
	// glfw_draw_bitmap(this->area, (MAX_WIDTH / 2 - width / 2) * UNIT, (MAX_HEIGHT / 2 - height / 2) * UNIT, 0);

}

key			DlGlfw::keyEvent(void)
{
	key		e = KEY_NONE;

	// glfwPollEvents();

	// if (glfw_is_event_queue_empty(this->e_queue))
	// 	return (KEY_NONE);
	// glfw_wait_for_event(this->e_queue, this->event);
	// if (this->event->type == GLFW_EVENT_DISPLAY_CLOSE)
	// 	return (KEY_EXIT);
	// else if (this->event->type == GLFW_EVENT_KEY_DOWN)
	// {
	// 	switch (this->event->keyboard.keycode)
	// 	{
	// 		case GLFW_KEY_A:
	// 			return (KEY_LEFT_A);
	// 		case GLFW_KEY_S:
	// 			return (KEY_RIGHT_A);
	// 		case GLFW_KEY_G:
	// 			return (KEY_LEFT_B);
	// 		case GLFW_KEY_H:
	// 			return (KEY_RIGHT_B);
	// 		case GLFW_KEY_K:
	// 			return (KEY_LEFT_C);
	// 		case GLFW_KEY_L:
	// 			return (KEY_RIGHT_C);
	// 		case GLFW_KEY_LEFT:
	// 			return (KEY_LEFT_D);
	// 		case GLFW_KEY_RIGHT:
	// 			return (KEY_RIGHT_D);

	// 		case GLFW_KEY_1:
	// 			return (KEY_LIB_A);
	// 		case GLFW_KEY_2:
	// 			return (KEY_LIB_B);
	// 		case GLFW_KEY_3:
	// 			return (KEY_LIB_C);

	// 		case GLFW_KEY_ESCAPE:
	// 			return (KEY_EXIT);
	// 		default:
	// 			break ;
	// 	}
	// }
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

	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (!(dl->win = glfwCreateWindow(MAX_HEIGHT * UNIT,
									 MAX_WIDTH * UNIT,
									 "GLFW", NULL, NULL)))
	{
		std::cout << "Error : glfwCreateWindow" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetErrorCallback(error_callback);
	glDisable(GL_CULL_FACE);

	//TODO: center window?

	glClearColor(WHITE, 255);
	glfwMakeContextCurrent(dl->win);

	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// glOrtho(0., MAX_WIDTH * UNIT, MAX_HEIGHT * UNIT, 0., 0., 1.);
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();
	// glViewport(0, 0, MAX_WIDTH * UNIT, MAX_HEIGHT * UNIT);
	// glfwSwapInterval(1);
	// glEnable(GL_DEPTH_TEST); // enable depth-testing
	// glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

	glewExperimental = GL_TRUE;
	glewInit();

	glfwPollEvents();			// DEBUG

	return (dynamic_cast<IDl*>(dl));
}
