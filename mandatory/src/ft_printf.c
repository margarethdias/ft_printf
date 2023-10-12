/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meg <meg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:50:23 by mdias             #+#    #+#             */
/*   Updated: 2023/10/12 14:41:07 by meg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, const char *format, int i)
{
	int	len;

	len = 0;
	if (format[i] == '%')
		len += ft_printchar('%');
	else if (format[i] == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format[i] == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format[i] == 'i' || format[i] == 'd')
		len += ft_printnbr(va_arg(args, int));
	else if (format[i] == 'u')
		len += ft_printnbr_uns(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		len += ft_printnbr_hex(va_arg(args, unsigned int), HEXABASE);
	else if (format[i] == 'X')
		len+= ft_printnbr_hex(va_arg(args, unsigned int), HEXAUPPER);
	else if (format[i] == 'p')
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
		if (format[i] == '%' || format[i] != 0)
		{
			i++;
			len += ft_check_format(args, format, i);
		}
		else
		{
			ft_printchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}