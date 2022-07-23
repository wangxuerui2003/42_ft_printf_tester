/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:30:12 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/23 22:12:14 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_header.h"

void	init_status(t_status *status)
{
	status->current_test = 0;
	status->test_params = NULL;
	status->tests_correct = 0;
	status->tests_runned = 0;
}

int	should_test(t_flags *flags, t_status *status)
{
	if (flags->test_num == 0)
		return (1);
	if (flags->test_num != 0 && flags->test_num == status->current_test)
		return (1);
	return (0);
}

void	prepare_redir(int fd[2])
{
	close(fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
}

void	get_result(t_result *result, int fd[2])
{
	char	*temp;
	int		byteread;

	temp = malloc((BUFFER + 1) * sizeof(char));
	close(fd[WRITE]);
	byteread = read(fd[READ], temp, BUFFER);
	temp[byteread] = '\0';
	result->output = temp;
	close(fd[READ]);
}

int	check_result(t_status *status, int exitpid,
	t_result *stdresult, t_result *userresult)
{
	if (exitpid != 0)
	{
		ft_putstr_fd(RED, 1);
		if (exitpid == SIGSEGV)
			ft_putstr_fd("SEG_FAULT! " RESET, 1);
		else if (exitpid == SIGKILL)
			ft_putstr_fd("TIMEOUT! (more than 1 second) " RESET, 1);
		else if (exitpid == SIGABRT)
			ft_putstr_fd("SIGABRT! " RESET, 1);
		else if (exitpid == LEAKS_ERROR)
		{
			ft_putstr_fd(RED "LEAKS!" RESET, 1);
			return (0);
		}
		else
			ft_putstr_fd("Unknown Crash! " RESET, 1);
		return (0);
	}
	if (strcmp(stdresult->output, userresult->output) == 0
		&& stdresult->return_value == userresult->return_value)
	{
		ft_putstr_fd(GREEN "OK! " RESET, STDOUT_FILENO);
		return (1);
	}
	ft_putstr_fd(RED "KO! " RESET, STDOUT_FILENO);
	print_help(status, stdresult, userresult);
	sleep(1);
	return (0);
}
