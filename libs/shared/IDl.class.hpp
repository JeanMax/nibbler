/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDl.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:32:57 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 19:50:14 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDL_CLASS_HPP
# define IDL_CLASS_HPP

# include <iostream>

//tmp only there for debugging
class Map{
	public : 
	int		e;
};
class e_key{
	public :
	int		e;
};

enum		e_type
{
	T_SDL,
	T_SFML,
	T_ALLEGRO,
	T_NONE
};

class		IDl
{
	public:

//constructors
	IDl(void);
	IDl(IDl const &rhs);

//operator overload
	IDl	&operator=(IDl const &rhs);

//destructors
	virtual ~IDl(void);

//actions
 	virtual void	print(Map map) const = 0;
	virtual e_key	keyEvent(void) const = 0;
};

extern "C" IDl			*init(e_type e);
extern "C" void			close(IDl *dl);

#endif
