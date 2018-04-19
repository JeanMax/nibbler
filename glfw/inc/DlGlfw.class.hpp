/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlGlfw.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:27 by bmbarga           #+#    #+#             */
//   Updated: 2018/04/19 15:34:41 by mcanal           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef DLGLFW_CLASS_HPP
# define DLGLFW_CLASS_HPP

# include "IDl.class.hpp"
# include <GL/glew.h>
# include <GLFW/glfw3.h>

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

class		DlGlfw : public IDl
{
	public:
	GLFWwindow			*win;

//constructors
	DlGlfw(void);
	DlGlfw(DlGlfw const &rhs);

//destructor
	virtual			~DlGlfw(void);

//operator overload
	DlGlfw	&operator=(DlGlfw const &rhs);

//actions
 	virtual void	print(enum game_entity **map, const unsigned int width, const unsigned int height);
	virtual key		keyEvent(void);
};

#endif
