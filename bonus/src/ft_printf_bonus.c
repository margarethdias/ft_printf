/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:50:23 by mdias             #+#    #+#             */
/*   Updated: 2023/10/22 19:08:05 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_handle_hash(unsigned int nbr, const char format, const char flag)
{
	int	size;

	size = 0;
	if (flag == '#' && nbr != 0)
	{
		if (format == 'x')
			size += write(1, "0x", 2);
		if (format == 'X')
			size += write(1, "0X", 2);
	}
	if (format == 'x')
		size += ft_printnbr_hex(nbr, HEXABASE);
	if (format == 'X')
		size += ft_printnbr_hex(nbr, HEXAUPPER);
	return (size);
}

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
		len += ft_handle_hash(va_arg(args, unsigned int), format, flag);
	else if (format == 'X')
		len += ft_handle_hash(va_arg(args, unsigned int), format, flag);
	else if (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long), HEXABASE);
	return (len);
}

void	handle_format(const char *frmt, int *i, va_list args, int *len)
{
	if (frmt[*i + 1] == '#' || frmt[*i + 1] == ' ' || frmt[*i + 1] == '+')
	{
		*len += ft_check_flags(args, frmt[*i + 2], frmt[*i + 1]);
		*i += 2;
	}
	else
	{
		*len += ft_check_flags(args, frmt[*i + 1], NO_FLAG);
		(*i)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i] && (format[i + 1] != 0 || format[i] != '%'))
	{
		if (format[i] == '%' && format[i + 1] != 0)
			handle_format(format, &i, args, &len);
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
