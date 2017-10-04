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

class		DlAllegro : public IDl
{
	public:
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
