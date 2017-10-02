// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 22:39:03 by mc                #+#    #+#             //
//   Updated: 2017/10/02 17:21:28 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"

/*
** constructor
*/
Player::Player(const std::string &name, enum player player, const Map *map) :
    _name(name),
    _body({}),
    _score(0),
    _direction(NONE),
    _player(player),
    _x(UINT_MAX),
    _y(UINT_MAX),
    _map(map)
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

void               Player::turn(enum direction direction)
{
    if (direction == RIGHT) {
        this->_direction = static_cast<enum direction>(
            (this->_direction + 1) % NONE
        );
    } else if (direction == LEFT) {
        this->_direction = static_cast<enum direction>(
            ABS(this->_direction - 1) % NONE
        );
    }
}

void               Player::moveForward()
{
    if (!this->isAlive()) {
        return;
    }

    this->_move(this->_direction);
    if (!this->_eat(*(this->_map->getArea() + this->_y) + this->_x)) {
        this->_poop();
    }
}



/*
** private
*/
void               Player::_move(enum direction direction)
{
    if (!this->isAlive()) {
        return;
    }

    if (direction == UP) {
        this->_y++;
    } else if (direction == DOWN) {
        this->_y--;
    } else if (direction == RIGHT) {
        this->_x++;
    } else if (direction == LEFT) {
        this->_x--;
    }

    if (this->_map->get(this->_x, this->_y) == OUTER_WALL) {
        this->_die();
        return;
    }

    //TODO: loop when outside of map
}

bool               Player::_eat(game_entity *entity)
{
    bool ate = false;

    if (!this->isAlive()) {
        return false;
    }

    if (*entity == FOOD) {
        this->_score += FOOD_SCORE;
        ate = true;
    } else if (*entity == BONUS) {
        this->_score += BONUS_SCORE;
        ate = true;
    } else if (*entity != EMPTY) {
        this->_die();
        return false;
    }

    *entity = static_cast<enum game_entity>(SNAKE_A + this->_player);
    this->_body.push_front(entity);

    return ate;
}

void               Player::_poop()
{
    if (!this->isAlive()) {
        return;
    }

    *this->_body.back() = EMPTY;
    this->_body.pop_back();
}

void               Player::_die()
{
    if (!this->isAlive()) {
        return;
    }

    while (!this->_body.empty()) {
        *this->_body.front() = EMPTY;
        this->_body.pop_front();
    }
}
