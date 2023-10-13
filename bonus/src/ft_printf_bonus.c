/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:50:23 by mdias             #+#    #+#             */
/*   Updated: 2023/10/13 20:13:31 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check_flags(va_list args, const char format, const char flag)
{
	int	len;

	len = 0;
	if (format == '%')
		len += ft_printchar('%');
	else if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		len += ft_printnbr(va_arg(args, int), flag);
	else if (format == 'u')
		len += ft_printnbr_uns(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_printnbr_hex(va_arg(args, unsigned int), HEXABASE, flag);
	else if (format == 'X')
		len += ft_printnbr_hex(va_arg(args, unsigned int), HEXAUPPER, flag);
	else if (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long), HEXABASE);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == 0)
			return (len);
		if (format[i] == '%' && format[i + 1] != 0)
		{
			if (format[i + 1] == '#' || format[i + 1] == ' ' 
				|| format[i + 1] == '+')
			{
				len += ft_check_flags(args, format[i + 2], format[i + 1]);
				i += 2;
			}
			else
			{
				len += ft_check_flags(args, format[i + 1], NO_FLAG);
				i++;
			}
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
