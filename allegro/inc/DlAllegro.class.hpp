/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlAllegro.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:27 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/03 19:57:14 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLALLEGRO_CLASS_HPP
# define DLALLEGRO_CLASS_HPP

#include "IDl.class.hpp"
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef	struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

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

class		DlAllegro : public IDl
{
	public:
	ALLEGRO_DISPLAY			*win;
	ALLEGRO_EVENT_QUEUE		*e_queue;
	ALLEGRO_EVENT			*event;
	ALLEGRO_BITMAP			*area;

//constructors
	DlAllegro(void);
	DlAllegro(DlAllegro const &rhs);

//destructor
	virtual			~DlAllegro(void);

//operator overload
	DlAllegro	&operator=(DlAllegro const &rhs);

//actions
 	virtual void	print(enum game_entity **map, const unsigned int width, const unsigned int height);
	virtual key		keyEvent(void);
};

#endif
