/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:28:15 by mdias             #+#    #+#             */
/*   Updated: 2023/10/17 23:22:41 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

# define HEXABASE "0123456789abcdef"
# define HEXAUPPER "0123456789ABCDEF"
# define NO_FLAG '0'

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
int		ft_printnbr(int nbr, const char flag);

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

/**@brief Handle the '#' flag in printf formatting for hexadecimal numbers.
 *
 * @param nbr The unsigned integer to which the '#' flag is applied.
 * @param format The format specifier ('x' or 'X') for the hexadecimal output.
 * @param flag The flag ('#') indicating whether to include the prefix.
 * @return The number of characters printed, including any prefix.
 */
int		ft_handle_hash(unsigned int nbr, const char format, const char flag);

/**@brief Check and handle various format specifiers 
 * and flags in printf-style formatting.
 *
 * @param args The va_list containing the arguments.
 * @param format The format specifier 
 * ('%', 'c', 's', 'i', 'd', 'u', 'x', 'X', 'p').
 * @param flag The flag ('#', ' ', '+') indicating special formatting.
 * @return The number of characters printed based on the format and arguments.
 */
int		ft_check_flags(va_list args, const char format, const char flag);

/**@brief Handle formatting options when encountering a '%' 
 * character in the format string.
 *
 * @param frmt The format string.
 * @param i Pointer to the current position in the format string.
 * @param args The va_list containing the arguments.
 * @param len Pointer to the total length of characters printed.
 */
void	handle_format(const char *frmt, int *i, va_list args, int *len);

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
