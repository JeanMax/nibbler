/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:20:20 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 21:24:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <iostream>
#include "IDl.class.hpp"
#include "DlSdl.class.hpp"

#define PATH_SDL		"libdlsdl.so"
#define PATH_SFML		"libdlsfml.so"
#define PATH_ALLEGRO	"libdlallegro.so"

static std::string	paths[3] = {\
								PATH_SDL,\
								PATH_SFML,\
								PATH_ALLEGRO,\
								};

static void		load(int i)
{
	Map		m;
	IDl		*dl;
	void	*dl_handle;
	IDl		*(*init)();
	void	(*close)(IDl*);

	if (!(dl_handle = dlopen(paths[i].c_str(), RTLD_LAZY | RTLD_LOCAL)))
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	init = (IDl *(*)())dlsym(dl_handle, "init");
	if (!init)
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	dl = init();
 	dl->print(m);
	close = (void (*)(IDl*))dlsym(dl_handle, "close");
	if (!init)
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
 	close(dl);
}

int			main(int ac, char **av)
{
	load(0);
	load(1);
	load(2);
	(void)ac;
	(void)av;
	return (0);
}
