/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:03:04 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/04 17:41:56 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	cmp;

	i = 0;
	cmp = 0;
	while (!cmp && i < n && s1[i] && s2[i])
	{
		cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (!cmp && i < n && (s1[i] || s2[i]))
		cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (cmp);
}
