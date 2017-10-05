/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSfml.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:03:50 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/03 19:17:53 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLSFML_CLASS_HPP
# define DLSFML_CLASS_HPP

#include "IDl.class.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

typedef	struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

//black
t_color					g_col_black = {
					0,
					0,
					0,
					255
};
extern t_color			g_col_black;

//white
t_color					g_col_white = {
					255,
					255,
					255,
					255
};
extern t_color			g_col_white;

//red
t_color					g_col_pa = {
					255,
					0,
					0,
					255
};
extern t_color			g_col_pa;

//green
t_color					g_col_pb = {
					0,
					255,
					0,
					255
};
extern t_color			g_col_pb;

//blue
t_color					g_col_pc = {
					0,
					0,
					255,
					255
};
extern t_color			g_col_pc;

//yellow
t_color					g_col_pd = {
					255,
					255,
					0,
					255
};
extern t_color			g_col_pd;

t_color					g_col_bonus = {
					255,
					0,
					255,
					255
};
extern t_color			g_col_bonus;

class		DlSfml : public IDl
{
	public:
	sf::RenderWindow		*win;
	sf::RenderTexture		*area;
	sf::Event				*event;

//constructors
	DlSfml(void);
	DlSfml(DlSfml const &rhs);

//destructor
	virtual			~DlSfml(void);

//operator overload
	DlSfml	&operator=(DlSfml const &rhs);

//actions
 	virtual void	print(enum game_entity **map,
							const unsigned int width,
							const unsigned int height);

	virtual key		keyEvent(void);
};

#endif
