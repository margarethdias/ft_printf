/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:22:21 by mdias             #+#    #+#             */
/*   Updated: 2023/10/17 23:27:04 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXABASE "0123456789abcdef"
# define HEXAUPPER "0123456789ABCDEF"

/**@brief Print a single character to the standard output.
 *
 * @param c The character to be printed.
 * @return 1, indicating the number of characters printed (always 1).
 */
int		ft_printchar(char c);

/**@brief Print a string to the standard output.
 *
 * @param str The string to be printed.
 * @return The number of characters printed, 
 * or 6 if the string is NULL (for "(null)").
 */
int		ft_printstr(char *str);

/**@brief Print an integer to the standard output.
 *
 * @param nbr The integer to be printed.
 * @return The number of characters printed, 
 * including the negative sign (if applicable).
 */
int		ft_printnbr(int nbr);

/**@brief Print an unsigned integer to the standard output.
 *
 * @param nbr The unsigned integer to be printed.
 * @return The number of characters printed.
 */
int		ft_printnbr_uns(unsigned int nbr);

/**@brief Print an unsigned integer in hexadecimal format 
 * using the specified character set.
 *
 * @param hex The unsigned integer to be printed in hexadecimal.
 * @param base A character string defining the symbols for the hexadecimal base
 * @return The number of characters printed.
 */
int		ft_printnbr_hex(unsigned int hex, char *base);

/**@brief Print a memory address in hexadecimal format using 
 * the specified character set.
 *
 * @param ptr The memory address to be printed in hexadecimal.
 * @param base A character string defining the symbols for the hexadecimal base
 * @return The number of characters printed.
 */
int		ft_printptr(unsigned long ptr, char *base);

/**@brief Check and handle various format specifiers in printf-style formatting
 *
 * @param args The va_list containing the arguments.
 * @param format The format specifier 
 * ('%', 'c', 's', 'i', 'd', 'u', 'x', 'X', 'p').
 * @return The number of characters printed based on the format and arguments.
 */
int		ft_check_format(va_list args, char format);

/**@brief A custom implementation of printf-style 
 * formatting for various data types.
 *
 * @param format The format string that specifies how to format 
 * and print the data.
 * @param ... A variable number of arguments that correspond 
 * to the format specifiers.
 * @return The total number of characters printed.
 */
int		ft_printf(const char *format, ...);

#endif
