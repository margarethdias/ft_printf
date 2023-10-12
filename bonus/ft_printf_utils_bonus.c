/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:50:51 by mdias             #+#    #+#             */
/*   Updated: 2023/10/12 20:02:14 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[size])
	{
		write(1, &str[size], 1);
		size++;
	}
	return (size);
}
