// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc </var/spool/mail/mc>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/09/30 15:00:16 by mc                #+#    #+#             //
//   Updated: 2017/09/30 15:25:56 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include "log.hpp"

# define MIN_WIDTH      9
# define MAX_WIDTH      1000
# define DEFAULT_WIDTH  16

# define MIN_HEIGHT     9
# define MAX_HEIGHT     1000
# define DEFAULT_HEIGHT 16

class Map {
    public:
        Map(const int width = DEFAULT_WIDTH, const int height = DEFAULT_HEIGHT);
        Map(Map const &copy);
        ~Map(void);
        Map const &operator=(Map const &copy);

        char *getArea() const;
        int   getWidth() const;
        int   getHeight() const;
        //TODO: next_frame()

    private:
        char     *_area;
        const int _width;
        const int _height;
        //TODO: players
};

#endif // MAP_HPP
