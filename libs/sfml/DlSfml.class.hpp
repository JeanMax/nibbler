/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DlSfml.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 20:03:50 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 20:03:53 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLSFML_CLASS_HPP
# define DLSFML_CLASS_HPP

#include "IDl.class.hpp"

class		DlSfml : public IDl
{
	public:
//constructors
	DlSfml(void);
	DlSfml(DlSfml const &rhs);

//destructor
	virtual			~DlSfml(void);

//operator overload
	DlSfml	&operator=(DlSfml const &rhs);

//actions
 	virtual void	print(Map map) const;
	virtual e_key	keyEvent(void) const;
};

#endif
