/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:22:21 by mdias             #+#    #+#             */
/*   Updated: 2023/10/12 17:20:30 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXABASE "0123456789abcdef"
# define HEXAUPPER "0123456789ABCDEF"

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int nbr);
int	ft_printnbr_uns(unsigned int nbr);
int	ft_printnbr_hex(unsigned int hex, char *base);
int	ft_printptr(unsigned long int, char *base);
int	ft_printf(const char *format, ...);

#endif
