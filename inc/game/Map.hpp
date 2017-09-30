// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc </var/spool/mail/mc>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 15:00:16 by mc                #+#    #+#             //
//   Updated: 2017/09/30 22:15:34 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include "log.hpp"
# include <cstdlib>
# include <cstring>

# define MIN_WIDTH      9
# define MAX_WIDTH      1000
# define DEFAULT_WIDTH  16

# define MIN_HEIGHT     9
# define MAX_HEIGHT     1000
# define DEFAULT_HEIGHT 16

# define FIRST_ROW

enum map_entity : char {
    OUTER_WALL = '\0',
    INNER_WALL = 'w',
    FRUIT = 'f',
    BONUS = 'b',
    SNAKE = 's',
    EMPTY = ' ',
};

typedef unsigned int t_uint;

class Map {
    public:
        Map(
            const t_uint width = DEFAULT_WIDTH,
            const t_uint height = DEFAULT_HEIGHT
        );
        Map(Map const &copy);
        ~Map(void);
        Map const &operator=(Map const &copy);

        map_entity **getArea() const;
        t_uint       getWidth() const;
        t_uint       getHeight() const;
        //TODO: next_frame()

    private:
        bool        _allocArea();

        map_entity  **_area;
        const t_uint _width;
        const t_uint _height;
        //TODO: players
};

#endif // MAP_HPP
