/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:30:12 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/24 15:48:48 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_header.h"

/*set all status to default*/
void	init_status(t_status *status)
{
	status->current_test = 0;
	status->test_params = NULL;
	status->tests_correct = 0;
	status->tests_runned = 0;
}
/*check if a test should be tested*/
int	should_test(t_flags *flags, t_status *status)
{
	if (flags->test_num != 0 && flags->test_num == status->current_test)
		return (1);
	if (flags->should_test == 0)
		return (0);
	if (flags->test_num == 0)
		return (1);
	return (0);
}

/*prepare pipes for redirecting STDOUT to the pipe*/
void	prepare_redir(int fd[2], int return_fd[2])
{
	close(fd[READ]);
	close(return_fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
}

/*get the output and return value from the pipes*/
void	get_result(t_result *result, int fd[2], int return_fd[2])
{
	char	*temp;
	char	*temp2;
	int		byteread;

	temp = malloc((BUFFER + 1) * sizeof(char));
	close(fd[WRITE]);
	close(return_fd[WRITE]);
	byteread = read(fd[READ], temp, BUFFER);
	temp[byteread] = '\0';
	result->output = temp;
	temp2 = malloc((BUFFER + 1) * sizeof(char));
	byteread = read(return_fd[READ], temp2, BUFFER);
	temp2[byteread] = '\0';
	result->return_value = atoi(temp2);
	free(temp2);
	close(fd[READ]);
	close(return_fd[READ]);
}

/*check errors*/
int	check_result(t_status *status, int exitpid,
	t_result *stdresult, t_result *userresult)
{
	if (exitpid != 0 && exitpid != LEAKS_ERROR)
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
		if (exitpid == LEAKS_ERROR)
		{
			ft_putstr_fd(RED "LEAKS!" RESET, 1);
			return (0);
		}
		return (1);
	}
	ft_putstr_fd(RED "KO! " RESET, STDOUT_FILENO);
	if (exitpid == LEAKS_ERROR)
	{
		ft_putstr_fd(RED "LEAKS!" RESET, 1);
		return (0);
	}
	print_help(status, stdresult, userresult);
	sleep(1);
	return (0);
}
