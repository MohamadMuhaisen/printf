/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:19:32 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/15 16:26:34 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_putnbr_hex(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hex(nbr / 16, base);
		count += ft_putnbr_hex(nbr % 16, base);
	}
	else
		count += write(1, &base[nbr], 1);
	return (count);
}

int	ft_putptr_fd(void *ptr)
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
	count += ft_putnbr_hex(addr, "0123456789abcdef");
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = n;
	if (nb / 10)
	{
		count += ft_putnbr_unsigned(nb / 10, fd);
	}
	count += write(fd, &"0123456789"[n % 10], 1);
	return (count);
}

int	ft_putnbr_hex_lower(unsigned int nbr)
{
	return (ft_putnbr_hex(nbr, "0123456789abcdef"));
}

int	ft_putnbr_hex_upper(unsigned int nbr)
{
	return (ft_putnbr_hex(nbr, "0123456789ABCDEF"));
}