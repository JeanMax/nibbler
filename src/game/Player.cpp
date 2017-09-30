// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:39:03 by mc                #+#    #+#             //
//   Updated: 2017/09/30 23:05:36 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"

/*
** constructor
*/
Player::Player(const std::string &name) :
    _name(name), _body({}), _score(0)
{
    DEBUG("Player constructor");
}

Player::Player(Player const &copy)
{
    DEBUG("Player copy");

    *this = copy;
}


/*
** destructor
*/
Player::~Player(void)
{
    DEBUG("Player destructor");
}


/*
** operator overload
*/
Player const  &Player::operator=(Player const &copy)
{
    (void)copy;
    return *this;
}


/*
** public
*/
const std::string &Player::getName() const
{
    return this->_name;
}

t_uint             Player::getScore() const
{
    return this->_score;
}

bool               Player::isAlive() const
{
    return !this->_body.empty();
}

void               Player::die()
{
    this->_body.clear(); //TODO: be sure it won't fuck up the Map
}


/*
** private
*/
