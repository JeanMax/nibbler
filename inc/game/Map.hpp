// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc </var/spool/mail/mc>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 15:00:16 by mc                #+#    #+#             //
//   Updated: 2017/10/01 00:38:01 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include "game_util.hpp"
# include <cstdlib>
# include <cstring>

# define MIN_WIDTH      9
# define MAX_WIDTH      1000
# define DEFAULT_WIDTH  16

# define MIN_HEIGHT     9
# define MAX_HEIGHT     1000
# define DEFAULT_HEIGHT 16

class Map {
    public:
        Map(
            const t_uint width = DEFAULT_WIDTH,
            const t_uint height = DEFAULT_HEIGHT
        );
        Map(Map const &copy);
        ~Map(void);
        Map const &operator=(Map const &copy);

        game_entity   get(t_uint x, t_uint y) const;
        game_entity **getArea() const;
        t_uint        getWidth() const;
        t_uint        getHeight() const;

    private:
        bool        _allocArea();

        game_entity **_area;
        const t_uint  _width;
        const t_uint  _height;
};

#endif // MAP_HPP
