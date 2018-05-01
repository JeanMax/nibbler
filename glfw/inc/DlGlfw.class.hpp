/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlGlfw.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:27 by bmbarga           #+#    #+#             */
//   Updated: 2018/04/19 20:25:29 by mcanal           ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#ifndef DLGLFW_CLASS_HPP
# define DLGLFW_CLASS_HPP

# include "IDl.class.hpp"
# include <GL/glew.h>
# include <GLFW/glfw3.h>

typedef	struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

//black
# define BLACK 0, 0, 0
# define WHITE 255, 255, 255
# define RED 255, 0, 0
# define GREEN 0, 255, 0
# define BLUE  0, 0, 255
# define YELLOW 255, 255, 0
# define MAGENTA 255, 255, 0

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
