/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSfml.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:03:03 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/03 19:18:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DlSfml.class.hpp"
#include <iostream>

DlSfml::DlSfml(void):IDl(), win(NULL), area(NULL), event(NULL)
{
}

DlSfml::~DlSfml(void)
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

 void		DlSfml::print(enum game_entity **map, const unsigned int width, const unsigned int height)
{
	t_rect			r;
	t_color			col;
	bool			fill;
	
	(void)map;
	(void)width;
	(void)height;
	(void)col;
	(void)fill;
	if (!this->area)
	{
		if (!(this->area = new sf::RenderTexture))
		{
			std::cout << "Error : texture area set to null" << std::endl;
			exit(EXIT_FAILURE);
		}
		this->area->create(width * UNIT, height * UNIT, false);
	}
// 	rect.setFillColor(sf::Color(10, 20, 30));
// 	rect.setPosition(20, 20);
// 	this->win->draw(rect);
	//clear background
	this->win->clear(sf::Color::White);

	//set map area
	this->area->clear(sf::Color::Black);

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
				//draw Shape
			 	sf::RectangleShape	rect(sf::Vector2f(r.w, r.h));
				if (fill)
					rect.setFillColor(sf::Color(col.r, col.g, col.b));
				else
				{
					rect.setFillColor(sf::Color::Black);
					rect.setOutlineThickness(1);
					rect.setOutlineColor(sf::Color(col.r, col.g, col.b));
				}
				//place
			 	rect.setPosition(r.x, r.y);

				//draw
				this->area->draw(rect);
			}
		}
	}

	this->area->display();
	setRect(&r, (MAX_WIDTH / 2 - width / 2) * UNIT,
				(MAX_HEIGHT / 2 - height / 2)  * UNIT, 0, 0);

	sf::Sprite sprite(this->area->getTexture());
	sprite.setPosition(r.x, r.y);
	this->win->draw(sprite);
	this->win->display();
}

key			DlSfml::keyEvent(void)
{
	key		e = KEY_NONE;

	if (!this->win->pollEvent(*this->event))
		return (KEY_NONE);
	if (this->event->type == sf::Event::Closed)
		return (KEY_EXIT);
	else if (this->event->type == sf::Event::KeyPressed)
	{
		switch (this->event->key.code)
		{
			case sf::Keyboard::A :
				return (KEY_LEFT_A);
			case sf::Keyboard::S :
				return (KEY_RIGHT_A);
			case sf::Keyboard::G :
				return (KEY_LEFT_B);
			case sf::Keyboard::H :
				return (KEY_RIGHT_B);
			case sf::Keyboard::K :
				return (KEY_LEFT_C);
			case sf::Keyboard::L :
				return (KEY_RIGHT_C);
			case sf::Keyboard::Left :
				return (KEY_LEFT_D);
			case sf::Keyboard::Right :
				return (KEY_RIGHT_D);

			case sf::Keyboard::Num1 :
				return (KEY_LIB_A);
			case sf::Keyboard::Num2 :
				return (KEY_LIB_B);
			case sf::Keyboard::Num3 :
				return (KEY_LIB_C);

			case sf::Keyboard::Escape :
				return (KEY_EXIT);
			default:
				break ;
		}
	}
	return (e);
}

void			dl_close(IDl *dl)
{
	DlSfml				*tmp;

	if (!(tmp = dynamic_cast<DlSfml*>(dl)))
	{
		std::cout << "Error : dl is set to null !"<< std::endl;
		exit(EXIT_FAILURE);
	}
	if (!dl)
		return ;
	delete(tmp->event);
	delete(tmp->area);
	delete(tmp->win);
	delete (dl);
}

IDl				*dl_init(void)
{
	DlSfml			*dl;

	if (!(dl = new DlSfml()))
	{
		std::cout << "Error : dl" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!(dl->win = new sf::RenderWindow(
			sf::VideoMode(MAX_WIDTH * UNIT, MAX_HEIGHT * UNIT),
			"SFML")))
	{
		std::cout << "Error : sf::RenderWindow " << std::endl;
		exit(EXIT_FAILURE);
	}

	//center window
	dl->win->setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - MAX_WIDTH * UNIT / 2,

 	 						(sf::VideoMode::getDesktopMode().height / 2) - MAX_HEIGHT * UNIT / 2));

	if (!(dl->event = new sf::Event))
	{
		std::cout << "Error : sf::Event " << std::endl;
		exit(EXIT_FAILURE);
	}

	//unable repeat key
	dl->win->setKeyRepeatEnabled(false);

	return (dynamic_cast<IDl*>(dl));
}
