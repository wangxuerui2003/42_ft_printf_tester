/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:54:24 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/12 21:23:43 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	int		zero;
	int		minus;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	char	c;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_putvoidptr(unsigned long long ptr, t_flags *flags);
int		ft_print_hex(unsigned int nbr, char *base, t_flags *flags);
int		ft_putunsign(unsigned int nb, t_flags *flags);
int		ft_putcharf(char c, t_flags *flags);
int		ft_putnbrf(int num, t_flags *flags);
int		ft_putstrf(char *str, t_flags *flags);
void	ft_get_flags(const char *format, int *i, t_flags *flags);
void	ft_set_flags(t_flags *flags);
int		ft_print_chars(char c, int rep);
int		ft_putnbrstrf(char *str, t_flags *flags);
char	*ft_uitoa_base(unsigned int num, char *base);

#endif
