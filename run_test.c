/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:51:24 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/23 17:13:37 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_header.h"

void	run_test(t_flags *flags, t_status *status)
{
	TEST(status, should_test(flags, status), ("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest"));
	TEST(status, should_test(flags, status), ("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest"));
	TEST(status, should_test(flags, status), ("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest"));
	TEST(status, should_test(flags, status), ("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest"));
}