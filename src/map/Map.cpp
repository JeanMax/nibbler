// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc </var/spool/mail/mc>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 15:00:18 by mc                #+#    #+#             //
//   Updated: 2017/09/30 15:25:57 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.hpp"

/*
** constructor
*/
Map::Map(const int width, const int height) :  _width(width), _height(height)
{
    DEBUG("Map constructor");
}

Map::Map(Map const &copy) :  _width(copy.getWidth()), _height(copy.getHeight())
{
    *this = copy;
    DEBUG("Map copy");
}


/*
** destructor
*/
Map::~Map(void)
{
    DEBUG("Map destructor");
}


/*
** operator overload
*/
Map const &Map::operator=(Map const &copy)
{
    (void)copy;
    return *this;
}


/*
** private
*/

/*
** public
*/
char *Map::getArea() const
{
    return this->_area;
}

int   Map::getWidth() const
{
    return this->_width;
}

int   Map::getHeight() const
{
    return this->_height;
}
