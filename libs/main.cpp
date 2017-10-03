/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:20:20 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/03 11:49:10 by bmbarga          ###   ########.fr       */
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

static void		load(int i)
{
	Map		m;
	IDl		*dl;
	IDl		*(*dl_init)();
	void	(*dl_close)(IDl*);

	load_symbols(&dl_init, &dl_close, i);

	//get dynamic library
	dl = dl_init();

	//game loop
	while (42)
	{
		std::cout << "BUG 1" << std::endl;//_DEBUG_//
		dl->keyEvent();
 	 	dl->print(m);
		std::cout << "BUG 2" << std::endl;//_DEBUG_//
	}

	//clode dynamic library
 	dl_close(dl);
}

int			main(int ac, char **av)
{
// 	load(0);
// 	load(1);
	load(2);
	(void)ac;
	(void)av;
	return (0);
}
