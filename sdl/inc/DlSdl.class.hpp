/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSdl.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:34:16 by bmbarga           #+#    #+#             */
//   Updated: 2018/04/14 16:00:28 by mcanal           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef DLSDL_CLASS_HPP
# define DLSDL_CLASS_HPP

# include <SDL.h>
# include "IDl.class.hpp"

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

class		DlSdl : public IDl
{

	public:
//attributes
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		*event;
	SDL_Texture		*area;

//constructors
	DlSdl(void);
	DlSdl(DlSdl const &rhs);

//destructor
	virtual			~DlSdl(void);

//operator overload
	DlSdl	&operator=(DlSdl const &rhs);

//actions
 	virtual void	print(enum game_entity **map, const unsigned int width, const unsigned int height);
	virtual key		keyEvent(void);
};

#endif
