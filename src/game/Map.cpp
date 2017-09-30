// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc </var/spool/mail/mc>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 15:00:18 by mc                #+#    #+#             //
//   Updated: 2017/10/01 01:20:36 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.hpp"

/*
** constructor
*/
Map::Map(const t_uint width, const t_uint height) :
    _area(NULL),
    _width(width),
    _height(height)
{
    DEBUG("Map constructor");

    if (!this->_allocArea()) {
        ERROR("error: map malloc bjorked");
        delete this;
        return;
    }
}

Map::Map(Map const &copy) :
    _area(NULL),
    _width(copy.getWidth()),
    _height(copy.getHeight())
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
Map const      &Map::operator=(Map const &copy)
{
    (void)copy;
    return *this;
}


/*
** public
*/
game_entity     Map::get(t_uint x, t_uint y) const
{
    if (x > this->_width || y > this->_height) {
        return OUTER_WALL;
    }

    return this->_area[y][x];
}

game_entity   **Map::getArea() const
{
    return this->_area;
}

t_uint          Map::getWidth() const
{
    return this->_width;
}

t_uint          Map::getHeight() const
{
    return this->_height;
}


/*
** private
*/
bool            Map::_allocArea()
{
    this->_area = static_cast<game_entity **>(
        malloc(sizeof(game_entity *) * (this->_height + 1))
    );
    if (!this->_area) {
        return false;
    }
    this->_area[this->_height] = NULL;

    for (t_uint y = 0; y < this->_height; y++) {
        this->_area[y] = static_cast<game_entity *>(
            malloc(sizeof(game_entity) * (this->_width + 1))
        );
        if (!this->_area) {
            return false;
        }
        memset(this->_area[y], EMPTY, this->_width);
        this->_area[y][this->_width] = OUTER_WALL;
    }

    return true;
}
