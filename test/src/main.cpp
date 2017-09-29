/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:32:38 by mcanal            #+#    #+#             */
//   Updated: 2017/09/29 15:48:38 by mc               ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "test_nibbler.h"

static void all_suites(char *search)
{
	MU_TEST_SUITE suite_dummy = {
		{test_dummy, "a_dummy_test"},
		{test_dummy, "the_same_dummy_test"},
	};


	if (search) {
		int test_run_before = g_tests_run; //hmmm...

		MU_RUN_TEST_FROM_SUITE(search, suite_dummy);

		if (test_run_before == g_tests_run) {
			fprintf(stderr, "+ Test %s: " CLR_RED "not found", search);
			exit(EXIT_FAILURE);
		}
	} else {
		MU_RUN_SUITE(suite_dummy, "dummy");
	}
}


MU_HAI(); //yep, this is really ugly :/

int main(int ac, char **av) //TODO: --help
{
	setbuf(stdout, NULL); /* TODO: find a better place for this */

	if (ac == 1) {
		all_suites(NULL);
	} else {
		while (*++av) {
			all_suites(*av);
		}
		printf("\n");
	}

	MU_KTHXBYE();
	return EXIT_SUCCESS;
}
