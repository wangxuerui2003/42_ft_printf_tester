/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:09:38 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/23 22:11:38 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HEADER_H
# define TESTER_HEADER_H

/*Built in headers*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

/*Colours*/
# define BOLD		"\x1b[1m"
# define RED		"\x1b[31m"
# define GREEN 		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

/*Constants*/
# define READ 0
# define WRITE 1
# define BUFFER 1000
# define LEAKS_ERROR 4242

/*flags struct*/
typedef struct s_flags {
	int	test_num;
	int	s;
	int	c;
	int	p;
	int	d;
	int	i;
	int	x;
	int	X;
	int	percent;
	int	bonus;
}	t_flags;

/*result struct, record the output and return value of printf and ft_printf*/
typedef struct s_result {
	char	*output;
	int		return_value;
}	t_result;

/*status variables struct*/
typedef struct s_status {
	int		tests_runned;
	int		current_test;
	int		tests_correct;
	char	*test_params;
}	t_status;

/*ft_printf prototype*/
int ft_printf(const char *, ...);

/*functions*/
void	run_test(t_flags *flags, t_status *status);
void	testing(t_flags *flags, t_status *status);
void	print_help(t_status *status, t_result *stdresult, t_result *userresult);
void	prepare_redir(int fd[2]);
int		should_test(t_flags *flags, t_status *status);
void	init_status(t_status *status);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int	check_result(t_status *status, int exitpid,
	t_result *stdresult, t_result *userresult);
void	get_result(t_result *result, int fd[2]);
size_t	ft_strlen(char *str);
void	handle_signals(int sig);
char	*get_file_content(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);


/*Testing macro*/
# define TEST(status, should_test, params) { \
	int					child; \
	int					fd[2]; \
	int					exitpid; \
	struct sigaction	sa; \
	int					do_test; \
	int					timeout_checker; \
	int					wstatus; \
	int					exit_sig = 0; \
	status->current_test++; \
	if (should_test == 0) \
		return ; \
	t_result	*stdresult = malloc(sizeof(t_result)); \
	t_result	*userresult = malloc(sizeof(t_result)); \
	status->tests_runned++; \
	ft_putnbr_fd(status->current_test, 1); \
	ft_putstr_fd(": ", 1); \
	pipe(fd); \
	child = fork(); \
	if (child == 0) \
	{ \
		prepare_redir(fd); \
		stdresult->return_value = printf params; \
		close(fd[WRITE]); \
		exit(0); \
	} \
	else \
	{ \
		wait(NULL); \
		get_result(stdresult, fd); \
	} \
	sa.sa_handler = &handle_signals; \
	sa.sa_flags = SA_RESTART; \
	pipe(fd); \
	do_test = fork(); \
	if (do_test == 0) \
	{ \
		sigaction(SIGSEGV, &sa, NULL); \
		sigaction(SIGABRT, &sa, NULL); \
		prepare_redir(fd); \
		userresult->return_value = ft_printf params; \
		close(fd[WRITE]); \
		exit(0); \
	} \
	timeout_checker = fork(); \
	if (timeout_checker == 0) \
	{ \
		sleep(1); \
		exit(0); \
	} \
	exitpid = wait(&wstatus); \
	if (exitpid == do_test) \
	{ \
		kill(timeout_checker, SIGKILL); \
		wait(NULL); \
		exit_sig = WEXITSTATUS(wstatus); \
	} \
	else if (exitpid == timeout_checker) \
	{ \
		kill(do_test, SIGKILL); \
		wait(&wstatus); \
		exit_sig = SIGKILL; \
	} \
	get_result(userresult, fd); \
	if (ft_strnstr(userresult->output, "leaks", ft_strlen(userresult->output)) != NULL) \
		exit_sig = LEAKS_ERROR; \
	status->test_params = #params; \
	status->tests_correct += check_result(status, exit_sig, stdresult, userresult); \
	free(stdresult->output); \
	if (exitpid != 0) \
		free(userresult->output); \
	free(stdresult); \
	free(userresult); \
}

#endif