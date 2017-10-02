// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/01 00:36:46 by mc                #+#    #+#             //
//   Updated: 2017/10/02 20:52:07 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"

/*
** constructor
*/
Game::Game(const t_uint width, const t_uint height, const char **players_names) :
    _map(Map(width, height)),
    _fps(DEFAULT_FPS),
    _tick(0),
    _start_time(time(NULL))
{
    DEBUG("Game constructor");

    if (!this->_allocPlayers(players_names)) {
        ERROR("error: players malloc bjorked");
        delete this;
        return;
    }
}

Game::Game(Game const &copy) : _start_time(time(NULL))
{
    WARNING("Game copy constructor : don't expect this to be useful");

    *this = copy;
}


/*
** destructor
*/
Game::~Game(void)
{
    DEBUG("Game destructor");

    this->_freePlayers();
}


/*
** operator overload
*/
Game const     &Game::operator=(Game const &copy)
{
    WARNING("Game operator= : don't expect this to be useful");

    (void)copy;
    return *this;
}


/*
** public
*/
void            Game::nextFrame()
{
    for (t_uint i = 0; i < this->_number_of_players; i++) {
        this->_players[i]->moveForward();
    }

    // assuming this function would be called at least once per second
    if (!(this->getEllapsedSeconds() % INCREASE_FPS_SECONDS_INTERVAL)) {
        this->_increaseFps();
    }
}

void            Game::sleepFrame()
{
    time_t tack = time(NULL);
    double frame_useconds = difftime(tack, this->_tick) * 1e6;
    double tosleep_useconds = FPS_TO_US(this->_fps) - frame_useconds;

    if (tosleep_useconds > 0) {
        usleep(static_cast<__useconds_t>(tosleep_useconds));
    } else if (this->_tick) {
        WARNING(
            "Game: frame took too long to sleep (extra time: "
            << static_cast<int>(
                   frame_useconds / FPS_TO_US(this->_fps) * 100. - 100.
               )
            << "%)"
        );
    }

    this->_tick = tack;
}

void            Game::handleEvent(enum key key)
{
    enum player player = static_cast<enum player>(key / MAX_PLAYERS);

    if (key >= KEY_EXIT) {
        return; //TODO: handle other events
    }

    if (player > this->_number_of_players - 1) {
        return;
    }

    this->_players[player]->turn(key % 2 ? RIGHT : LEFT);
}

const Map      &Game::getMap() const
{
    return this->_map;
}

const Player   &Game::getPlayer(enum player player) const
{
    if (player > this->_number_of_players - 1) {
        return *this->_players[this->_number_of_players - 1];
    }

    return *this->_players[player];
}

t_uint          Game::getNumberOfPlayers() const
{
    return this->_number_of_players;
}

bool            Game::isOver() const
{
    for (t_uint i = 0; i < this->_number_of_players; i++) {
        if (this->_players[i]->isAlive()) {
            return false;
        }
    }

    return true;
}

t_uint          Game::getFps() const
{
    return this->_fps;
}

t_uint          Game::getEllapsedSeconds() const
{
    return static_cast<t_uint>(difftime(time(NULL), this->_start_time));
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
            static_cast<enum player>(names_swap - players_names),
            &this->_map
        );
        (*players_swap)->init(this->_number_of_players);

        players_swap++;
        names_swap++;
    }

    return true;
}

void            Game::_freePlayers()
{
    for (t_uint i = 0; i < this->_number_of_players; i++) {
        delete this->_players[i];
    }
    free(this->_players);
}

t_uint          Game::_increaseFps()
{
    if (this->_fps < MAX_FPS) {
        this->_fps++; //TODO: percent increase instead?
    }

    return this->_fps;
}
