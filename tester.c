/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:48:28 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/23 17:45:31 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_header.h"

void	tester(t_status *status)
{
	int			exitpid;
	t_result	*stdresult;
	t_result	*userresult;

	stdresult = malloc(sizeof(t_result));
	userresult = malloc(sizeof(t_result));
	status->tests_runned++;
	ft_putnbr_fd(status->current_test, 1);
	ft_putstr_fd(": ", 1);
	get_stdresult(stdresult, status);
	exitpid = get_userresult(userresult, status);
	status->tests_correct += check_result(status, exitpid, stdresult, userresult);
	free(stdresult->output);
	if (exitpid != SIGKILL)
		free(userresult->output);
	free(stdresult);
	free(userresult);
}

void	get_stdresult(t_result *stdresult, t_status *status)
{
	int	child;
	int	fd[2];

	pipe(fd);
	child = fork();
	if (child == 0)
	{
		prepare_redir(fd);
		stdresult->return_value = ft_putstr_fd(status->correct_output, 1);
		close(fd[WRITE]);
		exit(0);
	}
	else
	{
		wait(NULL);
		get_result(stdresult, fd);
	}
}

void	handle_signals(int sig)
{
	if (sig == SIGSEGV)
		exit(SIGSEGV);
	if (sig == SIGABRT)
		exit(SIGABRT);
}

int	get_userresult(t_result *userresult, t_status *status)
{
	struct sigaction	sa;
	int					exitpid;
	int					do_test;
	int					timeout_checker;
	int					fd[2];
	int					wstatus;

	(void)status;
	sa.sa_handler = &handle_signals;
	sa.sa_flags = SA_RESTART;
	pipe(fd);
	do_test = fork();
	if (do_test == 0)
	{
		sigaction(SIGSEGV, &sa, NULL);
		sigaction(SIGABRT, &sa, NULL);
		prepare_redir(fd);
		userresult->return_value = ft_printf("test");
		close(fd[WRITE]);
		exit(0);
	}
	timeout_checker = fork();
	if (timeout_checker == 0)
	{
		sleep(1);
		exit(0);
	}
	exitpid = wait(&wstatus);
	if (exitpid == do_test)
	{
		kill(SIGKILL, timeout_checker);
		exitpid = 0;
	}
	else
	{
		kill(do_test, SIGKILL);
		exitpid = SIGKILL;
	}
	get_result(userresult, fd);
	return (exitpid);
}
