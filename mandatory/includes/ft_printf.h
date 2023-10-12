/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meg <meg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:50:29 by mdias             #+#    #+#             */
/*   Updated: 2023/10/11 23:46:34 by mdias              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

#  define HEXABASE "0123456789ABCDEF"
#  define HEXAUPPER "0123456789ABCDEF"

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int nbr);
int	ft_printnbr_uns(unsigned int nbr);
int	ft_printnbr_hex(unsigned int hex, char	*base);
int	ft_printptr(unsigned long int, char *base);

#endif
