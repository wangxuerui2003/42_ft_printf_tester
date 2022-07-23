/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:59 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/09 18:41:47 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chars(char c, int rep)
{
	int	len;

	len = 0;
	while (rep > 0)
	{
		ft_putchar(c);
		len++;
		rep--;
	}
	return (len);
}
