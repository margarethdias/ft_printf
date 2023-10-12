/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:50:29 by mdias             #+#    #+#             */
/*   Updated: 2023/10/11 21:39:13 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int nbr);
int	ft_printnbr_uns(unsigned int nbr);
int	ft_printnbr_hex(unsigned int hex, char	*base);

#endif
