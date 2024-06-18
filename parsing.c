/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:37:38 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/18 17:43:16 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	parse_c(va_list ap, t_format *format)
{
	int	count;

	count = write(1, &(char){va_arg(ap, int)}, 1);
	if (format->left_justify)
	{
		left_justify(format, &count, 1);
	}
	return (count);
}

int	parse_int(va_list ap, t_format *format)
{
	int	count;
	int	n;

	count = 0;
	n = va_arg(ap, int);
	if (format->plus == 1 && n >= 0)
		count += write(1, "+", 1);
	if (n == 0)
	{
		count++;
		write(1, "0", 1);
	}
	else
	{
		if (n < 0)
			count++;
		ft_putnbr_fd(n, 1);
		while (n != 0 && ++count)
			n /= 10;
	}
	format->field_width -= count;
	if (format->left_justify)
		left_justify(format, &count, 0);
	return (count);
}

int	parse_s(va_list ap, t_format *format)
{
	int		count;
	char	*str;
	int		len;
	int		padding;

	count = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (format->precision >= 0 && format->precision < len)
		len = format->precision;
	if (format->field_width > len)
		padding = format->field_width - len;
	else
		padding = 0;
	if (!format->left_justify)
		while (padding-- > 0)
			count += write(1, " ", 1);
	count += write(1, str, len);
	if (format->left_justify)
		while (padding-- > 0)
			count += write(1, " ", 1);
	return (count);
}

int	ft_putnbr_hex_lower(unsigned int nbr, t_format *format)
{
	return (ft_putnbr_hex(nbr, "0123456789abcdef", format, 1));
}

int	ft_putnbr_hex_upper(unsigned int nbr, t_format *format)
{
	return (ft_putnbr_hex(nbr, "0123456789ABCDEF", format, 1));
}
