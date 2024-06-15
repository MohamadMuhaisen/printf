/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:32:47 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/15 16:22:16 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_format
{
	int	left_justify;
	int	zero_pad;
	int	field_width;
	int	precision;
	int	alternate_form;
	int	space;
	int	plus;
}	t_format;

int	ft_printf(const char *str, ...);
int	ft_putnbr_hex(unsigned long nbr, char *base);
int	ft_putptr_fd(void *ptr);
int	ft_putnbr_unsigned(unsigned int n, int fd);
int	ft_putnbr_hex_lower(unsigned int nbr);
int	ft_putnbr_hex_upper(unsigned int nbr);

#endif