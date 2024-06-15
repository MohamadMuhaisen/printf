/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:32:26 by mmuhaise          #+#    #+#             */
/*   Updated: 2024/06/15 16:25:48 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

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

// int	main(void)
// {
// 	int printed_chars;
// 	int *ptr = NULL;

// 	printed_chars = ft_printf("Hello %c test test %c name is %s bla bla\n", 'X', 'Z', "Mohamad");
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("Pointer address: %p\n", ptr);
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("Pointer address: %p\n", NULL);
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("number: %d\n", 42);
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("number: %i\n", 42);
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("Unsigned number: %u\n", -1);
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("Percentage sign: %%\n");
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("Hexadecimal (lowercase): %x\n", 255);
// 	printf("Printed characters: %d\n", printed_chars);
// 	printed_chars = ft_printf("Hexadecimal (uppercase): %X\n", 255);
// 	printf("Printed characters: %d\n", printed_chars);
// }
