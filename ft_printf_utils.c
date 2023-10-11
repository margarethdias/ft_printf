/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:50:51 by mdias             #+#    #+#             */
/*   Updated: 2023/10/11 20:44:40 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_printstr(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[size])
	{
		write(1, str[size], 1);
		size++;
	}
	return(size);
}

int	ft_printnbr(int nbr)
{
	long int	i;
	int	size;
	
	i = nbr;
	size = 0;
	if (i < 0)
	{
		ft_printchar('-');
		i = -i;
		size++;
	}
	if (nbr >= 10)
	{
		size += ft_printbnr(i / 10);
		size += ft_printchar((i = i % 10) + '0');
	}
	return(size);
}
