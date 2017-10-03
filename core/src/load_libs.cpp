/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_libs.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:20:20 by bmbarga           #+#    #+#             */
//   Updated: 2017/10/03 22:22:09 by mc               ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <iostream>
#include "IDl.class.hpp"

#define PATH_SDL		"libdlsdl.so"
#define PATH_SFML		"libdlsfml.so"
#define PATH_ALLEGRO	"libdlallegro.so"

static std::string	paths[3] = {\
								PATH_SDL,\
								PATH_SFML,\
								PATH_ALLEGRO,\
								};

static void		load_symbols(IDl *(**dl_init)(void), void (**dl_close)(IDl*), int index)
{
	void	*dl_handle;

	if (!(dl_handle = dlopen(paths[index].c_str(), RTLD_LAZY | RTLD_LOCAL)))
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	*dl_init = (IDl *(*)())dlsym(dl_handle, "dl_init");
	if (!*dl_init)
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	*dl_close = (void (*)(IDl*))dlsym(dl_handle, "dl_close");
	if (!*dl_close)
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
}

void    		load(int i)
{
	Map		m;
	IDl		*dl;
	IDl		*(*dl_init)();
	void	(*dl_close)(IDl*);
	key		tmp;

	load_symbols(&dl_init, &dl_close, i);

	//get dynamic library
	dl = dl_init();

	//game loop
	while (42)
	{
		if ((tmp = dl->keyEvent()) == KEY_EXIT)
		{
			//quit loop
			//and close game
			break ;
		}
 	 	dl->print(m);
	}

	//clode dynamic library
 	dl_close(dl);
}
