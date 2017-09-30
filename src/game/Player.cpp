// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:39:03 by mc                #+#    #+#             //
//   Updated: 2017/09/30 23:46:31 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"

/*
** constructor
*/
Player::Player(const std::string &name) :
    _name(name), _body({}), _score(0), _direction(NONE)
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

enum direction     Player::getDirection() const
{
    return this->_direction;
}

enum direction     Player::setDirection(enum direction direction)
{
    this->_direction = direction;

    return this->_direction;
}

void               Player::die()
{
    if (this->isAlive()) {
        this->_body.clear(); //TODO: be sure it won't fuck up the Map
    }
}

void               Player::eat(game_entity *entity)
{
    if (!this->isAlive()) {
        return;
    }

    if (*entity == FRUIT) {
        this->_score += FRUIT_SCORE;
    } else if (*entity == BONUS) {
        this->_score += BONUS_SCORE;
    } else if (*entity != EMPTY) {
        this->die();
        return;
    }

    *entity = SNAKE;
    this->_body.push_front(entity);
}

void               Player::poop()
{
    if (this->isAlive()) {
        *this->_body.back() = EMPTY;
        this->_body.pop_back();
    }
}


/*
** private
*/
