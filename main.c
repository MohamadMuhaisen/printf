/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:32:26 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/14 14:45:18 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

static int	ft_putnbr_hex(unsigned long nbr, char *base)
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

static int	ft_putptr_fd(void *ptr)
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

static int	ft_putnbr_unsigned(unsigned int n, int fd)
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

static int	ft_putnbr_hex_lower(unsigned int nbr)
{
	return (ft_putnbr_hex(nbr, "0123456789abcdef"));
}

static int	ft_putnbr_hex_upper(unsigned int nbr)
{
	return (ft_putnbr_hex(nbr, "0123456789ABCDEF"));
}

int	parse_arg(char specifier, va_list ap)
{
	int		count;
	char	*str;
	int		n;

	count = 0;
	if (specifier == 'c')
		count += write(1, &(char){va_arg(ap, int)}, 1);
	else if (specifier == 's')
	{
		str = va_arg(ap, char *);
		if (str)
			while (*str)
				count += write(1, str++, 1);
		else
			count += write(1, "(null)", 6);
	}
	else if (specifier == 'p')
		count += ft_putptr_fd(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
	{
		n = va_arg(ap, int);
		if (n < 0)
			count++;
		ft_putnbr_fd(n, 1);
		while (n != 0 && ++count)
			n /= 10;
	}
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(ap, unsigned int), 1);
	else if (specifier == 'x')
		count += ft_putnbr_hex_lower(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		count += ft_putnbr_hex_upper(va_arg(ap, unsigned int));
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			count += parse_arg(*(++str), ap);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int printed_chars;
	int *ptr = NULL;
	
	printed_chars = ft_printf("Hello %c test test %c name is %s bla bla\n", 'X', 'Z', "Mohamad");
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("Pointer address: %p\n", ptr);
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("Pointer address: %p\n", NULL);
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("number: %d\n", 42);
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("number: %i\n", 42);
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("Unsigned number: %u\n", -1);
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("Percentage sign: %%\n");
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("Hexadecimal (lowercase): %x\n", 255);
	printf("Printed characters: %d\n", printed_chars);
	printed_chars = ft_printf("Hexadecimal (uppercase): %X\n", 255);
	printf("Printed characters: %d\n", printed_chars);
}
