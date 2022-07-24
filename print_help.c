/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:49:03 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/24 13:18:55 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_header.h"

void	print_help(t_status *status, t_result *stdresult, t_result *userresult)
{
	if (strcmp(stdresult->output, userresult->output) != 0)
		ft_putstr_fd(RED "(WRONG OUTPUT!)" RESET, STDOUT_FILENO);
	if (stdresult->return_value != userresult->return_value)
		ft_putstr_fd(RED "(WRONG RETURN!)" RESET, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	printf(GREEN "\tImagination\t: ");
	printf("[%s]\treturn: %d\n", stdresult->output, stdresult->return_value);
	printf(RED "\tREALITY\t\t: ");
	printf("[%s]\treturn: %d\n", userresult->output, userresult->return_value);
	printf(RESET "Your test is runned by: [ft_printf%s]\n", status->test_params);
	printf("You can rerun this test by " YELLOW);
	printf("sh start %d.\n\n", status->current_test);
	ft_putstr_fd(RESET, 1);
}

