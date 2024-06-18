/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:32:47 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/18 17:37:12 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

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

int		ft_printf(const char *str, ...);
int		ft_putnbr_hex(unsigned long nbr, char *base, t_format *format, int l);
int		ft_putptr_fd(void *ptr, t_format *format, int l);
int		ft_putnbr_unsigned(unsigned int n, int fd, t_format *format);
int		ft_putnbr_unsigned_recursive(unsigned int n, int fd);
int		ft_putnbr_hex_lower(unsigned int nbr, t_format *format);
int		ft_putnbr_hex_upper(unsigned int nbr, t_format *format);
void	left_justify(t_format *format, int *count, int limit);
int		parse_s(va_list ap, t_format *format);
int		parse_int(va_list ap, t_format *format);
void	init_format(t_format *format);
void	fill_format(const char **str, t_format *format);
int		parse_c(va_list ap, t_format *format);
int		parse_arg(const char **str, va_list ap);
int		ft_putnbr_hex_recursive(unsigned long nbr, char *base);

#endif