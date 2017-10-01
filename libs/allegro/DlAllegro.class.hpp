/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlAllegro.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:06:27 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 20:07:15 by bmbarga          ###   ########.fr       */
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
 	virtual void	print(Map map) const;
	virtual e_key	keyEvent(void) const;
};

#endif
