/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:09:14 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/24 15:49:36 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_header.h"

static void	set_no_flags(t_flags *flags)
{
	flags->test_num = 0;
	flags->s = 0;
	flags->c = 0;
	flags->p = 0;
	flags->d = 0;
	flags->u = 0;
	flags->i = 0;
	flags->x = 0;
	flags->X = 0;
	flags->percent = 0;
	flags->bonus = 1;
	flags->should_test = 0;
}

static void	set_default(t_flags *flags)
{
	flags->test_num = 0;
	flags->s = 1;
	flags->c = 1;
	flags->p = 1;
	flags->d = 1;
	flags->u = 1;
	flags->i = 1;
	flags->x = 1;
	flags->X = 1;
	flags->percent = 1;
	flags->bonus = 1;
	flags->should_test = 1;
}

static void	get_specific_flags(int ac, char **av, t_flags *flags)
{
	set_no_flags(flags);
	while (--ac > 0)
	{
		if (strcmp(av[ac], "c") == 0)
			flags->c = 1;
		if (strcmp(av[ac], "s") == 0)
			flags->s = 1;
		if (strcmp(av[ac], "p") == 0)
			flags->p = 1;
		if (strcmp(av[ac], "d") == 0)
			flags->d = 1;
		if (strcmp(av[ac], "u") == 0)
			flags->u = 1;
		if (strcmp(av[ac], "i") == 0)
			flags->i = 1;
		if (strcmp(av[ac], "x") == 0)
			flags->x = 1;
		if (strcmp(av[ac], "X") == 0)
			flags->X = 1;
		if (strcmp(av[ac], "%") == 0)
			flags->percent = 1;
	}
}

/* Get all the user input flags, set to default if nothing input */
static void	parse_flags(int ac, char **av, t_flags *flags)
{
	if (ac == 1)
	{
		set_default(flags);
		return ;
	}
	if (ac == 2 && atoi(av[1]))
	{
		set_no_flags(flags);
		flags->test_num = atoi(av[1]);
		return ;
	}
	if (ac == 2 && (strcmp(av[1], "m") == 0 || strcmp(av[1], "b") == 0))
	{
		set_default(flags);
		if (strcmp(av[1], "m") == 0)
			flags->bonus = 0;
		return ;
	}
	get_specific_flags(ac, av, flags);
}

/* Main logic of the tester
 * init flags and status, run the tests, and print the score
 */
int	main(int ac, char **av)
{
	t_flags		*flags;
	t_status	*status;
	int			correct;
	int			runned;

	status = malloc(sizeof(t_status));
	flags = malloc(sizeof(t_flags));
	parse_flags(ac, av, flags);
	init_status(status);
	run_test(flags, status);
	correct = status->tests_correct;
	runned = status->tests_runned;
	printf("\n%d tests got correct over %d tests\n", correct, runned);
	printf("Score: ");
	if (status->tests_correct * 100 / status->tests_runned >= 50)
		printf(GREEN);
	else
		printf(RED);
	printf("%d%%\n", status->tests_correct * 100 / status->tests_runned);
	ft_putstr_fd(RESET, 1);
	free(status);
	free(flags);
	//system("leaks tester");
	return (0);
}
