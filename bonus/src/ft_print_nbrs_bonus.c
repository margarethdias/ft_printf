/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:02:25 by mdias             #+#    #+#             */
/*   Updated: 2023/10/13 20:39:49 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printnbr(int nbr, const char flag)
{
	long int	i;
	int			size;

	i = nbr;
	size = 0;
	if (flag == ' ' || flag == '+')
	{
		if (i >= 0 && flag == ' ')
			size += ft_printchar(' ');
		if (i >= 0 && flag == '+')
			size += ft_printchar('+');
	}
	if (i < 0)
	{
		ft_printchar('-');
		i *= -1;
		size++;
	}
	if (i >= 10)
		size += ft_printnbr(i / 10, NO_FLAG);
	size += ft_printchar(i % 10 + '0');
	return (size);
}

int	ft_printnbr_uns(unsigned int nbr)
{
	int	size;

	size = 0;
	if (nbr >= 10)
		size += ft_printnbr_uns(nbr / 10);
	size += ft_printchar(nbr % 10 + '0');
	return (size);
}

int ft_handle_hash(const char format, const char flag)
{
	int size;
	
	size = 0;
	if (flag == '#')
		if (format == 'x')
			size += write(1, "0x", 2);
		if (format == 'X')
			size += write(1, "0X", 2);
}
int	ft_printnbr_hex(unsigned int hex, char *base)
{
	int	size;

	size = 0;
	if (hex < 16)
		size += ft_printchar(base[hex % 16]);
	else if (hex >= 16)
	{
		size += ft_printnbr_hex(hex / 16, base);
		size += ft_printchar(base[hex % 16]);
	}
	return (size);
}

int	ft_printptr(unsigned long ptr, char *base)
{
	int	size;

	size = 0;
	if (ptr == 0 || ((void *)ptr == NULL))
	{
		size += write(1, "(nil)", 5);
		return (size);
	}
	if (ptr < 16)
	{
		write(1, "0x", 2);
		size = 2;
		size += ft_printchar(base[ptr % 16]);
	}
	else if (ptr >= 16)
	{
		size += ft_printptr(ptr / 16, base);
		size += ft_printchar(base[ptr % 16]);
	}
	return (size);
}
