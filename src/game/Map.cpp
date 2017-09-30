// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc </var/spool/mail/mc>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 15:00:18 by mc                #+#    #+#             //
//   Updated: 2017/09/30 22:22:22 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.hpp"

/*
** constructor
*/
Map::Map(const t_uint width, const t_uint height) :
    _area(NULL), _width(width), _height(height)
{
    DEBUG("Map constructor");

    if (!this->_allocArea()) {
        ERROR("error: malloc bjorked");
        delete this;
        return;
    }
}

Map::Map(Map const &copy) :
    _area(NULL), _width(copy.getWidth()), _height(copy.getHeight())
{
    DEBUG("Map copy");

    *this = copy;
}


/*
** destructor
*/
Map::~Map(void)
{
    DEBUG("Map destructor");

    for (t_uint y = 0; y < this->_height; y++) {
        free(this->_area[y]);
    }
    free(this->_area);
}


/*
** operator overload
*/
Map const  &Map::operator=(Map const &copy)
{
    (void)copy;
    return *this;
}


/*
** public
*/
map_entity **Map::getArea() const
{
    return this->_area;
}

t_uint      Map::getWidth() const
{
    return this->_width;
}

t_uint      Map::getHeight() const
{
    return this->_height;
}


/*
** private
*/
bool        Map::_allocArea()
{
    this->_area = static_cast<map_entity **>(
        malloc(sizeof(map_entity *) * (this->_height + 1))
    );
    if (!this->_area) {
        return false;
    }
    this->_area[this->_height] = NULL;

    for (t_uint y = 0; y < this->_height; y++) {
        this->_area[y] = static_cast<map_entity *>(
            malloc(sizeof(map_entity) * (this->_width + 1))
        );
        if (!this->_area) {
            return false;
        }
        memset(this->_area[y], EMPTY, this->_width);
        this->_area[y][this->_width] = OUTER_WALL;
    }


    return true;
}
