/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:19:32 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/18 17:40:48 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_putnbr_hex_recursive(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hex_recursive(nbr / 16, base);
	}
	count += write(1, &base[nbr % 16], 1);
	return (count);
}

int	ft_putnbr_hex(unsigned long nbr, char *base, t_format *format, int l)
{
	int	count;

	count = ft_putnbr_hex_recursive(nbr, base);
	if (l)
		left_justify(format, &count, count);
	return (count);
}

int	ft_putptr_fd(void *ptr, t_format *format, int l)
{
	int				count;
	unsigned long	addr;

	count = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	addr = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += ft_putnbr_hex(addr, "0123456789abcdef", format, l);
	format->field_width -= count;
	left_justify(format, &count, 0);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n, int fd, t_format *format)
{
	int	count;

	count = ft_putnbr_unsigned_recursive(n, fd);
	format->field_width -= count;
	left_justify(format, &count, 0);
	return (count);
}

int	ft_putnbr_unsigned_recursive(unsigned int n, int fd)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = n;
	if (nb / 10)
	{
		count += ft_putnbr_unsigned_recursive(nb / 10, fd);
	}
	count += write(fd, &"0123456789"[nb % 10], 1);
	return (count);
}
