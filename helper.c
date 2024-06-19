/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:51:37 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/19 23:52:23 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_putnbr_hex_lower(unsigned int nbr, t_format *format)
{
	return (ft_putnbr_hex(nbr, "0123456789abcdef", format, 1));
}

int	ft_putnbr_hex_upper(unsigned int nbr, t_format *format)
{
	return (ft_putnbr_hex(nbr, "0123456789ABCDEF", format, 1));
}
