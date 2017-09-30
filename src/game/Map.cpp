// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc </var/spool/mail/mc>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 15:00:18 by mc                #+#    #+#             //
//   Updated: 2017/09/30 20:47:03 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.hpp"

/*
** constructor
*/
Map::Map(const int width, const int height) :
    _area(NULL), _width(width), _height(height)
{
    DEBUG("Map constructor");

    this->_area = static_cast<map_entity *>(
        malloc(sizeof(map_entity) * width * height)
    );
    if (!this->_area) {
        ERROR("error: malloc bjorked"); //TODO
    }
}

Map::Map(Map const &copy) :
    _area(NULL), _width(copy.getWidth()), _height(copy.getHeight())
{
    DEBUG("Map copy");

    if (copy.getArea()) {
        int len = sizeof(map_entity) * this->_width * this->_height;

        this->_area = static_cast<map_entity *>(malloc(len));
        if (this->_area) {
            memcpy(this->_area, copy.getArea(), len); //TODO: test
        } else {
            ERROR("error: malloc bjorked"); //TODO
        }
    }
}


/*
** destructor
*/
Map::~Map(void)
{
    DEBUG("Map destructor");

    if (this->_area) {
        free(this->_area);
    }
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
** public
*/
map_entity *Map::getArea() const
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


/*
** private
*/
