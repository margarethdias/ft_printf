/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:50:23 by mdias             #+#    #+#             */
/*   Updated: 2023/10/11 22:05:46 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_check_format(va_list args, const char *format, const char *flag)
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
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_printnbr_uns(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_printnbr_hex(va_arg(args, unsigned int), HEXABASE);
	else if (format == 'X');
		len+= ft_printnbr_hex(va_arg(args), HEXAUPPER)
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
		if (format[i] == '%')
		{
			if (format[i + 1] == '#' || format[i + 1] == ' ' || format[i
				+ 1] == '+')
				ft_check_format(va_list args, format[i], format[i + 1])
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

// printar:

// c - char
// s - string
// d e i - int
// u - unsigned int
// p - pointr
// x || X - hexadecimal
// % - %