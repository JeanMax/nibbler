// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/01 00:36:46 by mc                #+#    #+#             //
//   Updated: 2017/10/01 01:55:16 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"

/*
** constructor
*/
Game::Game(const t_uint width, const t_uint height, const char **players_names) :
    _map(Map(width, height))
{
    DEBUG("Game constructor");

    if (!this->_allocPlayers(players_names)) {
        ERROR("error: players malloc bjorked");
        delete this;
        return;
    }
}

Game::Game(Game const &copy)
{
    DEBUG("Game copy");

    *this = copy;
}


/*
** destructor
*/
Game::~Game(void)
{
    DEBUG("Game destructor");
}


/*
** operator overload
*/
Game const      &Game::operator=(Game const &copy)
{
    (void)copy;
    return *this;
}


/*
** public
*/
bool       Game::nextFrame()
{
    //TODO
    return true;
}

void       Game::sleepFrame()
{
    //TODO
}

void       Game::handleEvent(enum direction direction, enum player player)
{
    this->_players[player]->setDirection(direction);
}

const Map       &Game::getMap() const
{
    return this->_map;
}

const Player    &Game::getPlayer(enum player player) const
{
    if (player > this->_number_of_players - 1) {
        return *this->_players[this->_number_of_players - 1];
    }

    return *this->_players[player];
}

Player         **Game::getPlayers() const
{
    return this->_players;
}

t_uint           Game::getNumberOfPlayers() const
{
    return this->_number_of_players;
}

bool             Game::isOver() const
{
    for (t_uint i = 0; i < this->_number_of_players; i++) {
        if (this->_players[i]->isAlive()) {
            return false;
        }
    }

    return true;
}


/*
** private
*/
bool            Game::_allocPlayers(const char **players_names)
{
    const char **names_swap = players_names;
    Player     **players_swap;

    while (*names_swap) {
        names_swap++;
    }
    this->_number_of_players = static_cast<t_uint>(names_swap - players_names);

    this->_players = static_cast<Player **>(
        malloc(sizeof(Player *) * this->_number_of_players)
    );
    if (!this->_players) {
        return false;
    }

    players_swap = this->_players;
    names_swap = players_names;
    while (*names_swap) {
        *players_swap = new Player(
            *names_swap,
            static_cast<enum player>(names_swap - players_names)
        );

        players_swap++;
        names_swap++;
    }

    return true;
}
