/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:20:20 by bmbarga           #+#    #+#             */
/*   Updated: 2017/10/01 19:52:38 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <iostream>
#include "IDl.class.hpp"
#include "DlSdl.class.hpp"

#define PATH_SDL		"libdlsdl.so"
#define PATH_SFML		"./sdl/libdlsfml.so"
#define PATH_ALLEGRO	"./sdl/libdlallegro.so"

static std::string	paths[3] = {\
								PATH_SDL,\
								PATH_SFML,\
								PATH_ALLEGRO,\
								};

int			main(int ac, char **av)
{
	IDl		*dl;
	Map		m;
	void	*dl_handle;

	IDl		*(*init)(e_type);
	if (!(dl_handle = dlopen(paths[0].c_str(), RTLD_LAZY | RTLD_LOCAL)))
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	(void)init;
	init = (IDl *(*)(e_type))dlsym(dl_handle, "init");
	if (!init)
	{
		std::cout << "Error : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	dl = init(T_SDL);
 	dl->print(m);
	(void)ac;
	(void)av;
	(void)m;
	(void)dl;
// 	dl = init<DlSdl>("");
 	close(dl);
	return (0);
}
