/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSdl.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:34:16 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/02 19:00:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLSDL_CLASS_HPP
# define DLSDL_CLASS_HPP

# include <SDL.h>
# include "IDl.class.hpp"

class		DlSdl : public IDl
{

	public:
//attributes
	SDL_Window		*win;
	SDL_Event		*event;

//constructors
	DlSdl(void);
	DlSdl(DlSdl const &rhs);

//destructor
	virtual			~DlSdl(void);

//operator overload
	DlSdl	&operator=(DlSdl const &rhs);

//actions
 	virtual void	print(Map map) const;
	virtual e_key	keyEvent(void) const;
};

#endif
