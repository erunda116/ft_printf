/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:27:36 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/04 18:43:13 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printchar(int c);
int		ft_printdigit(int num);
void	ft_putstr(char *str);
void	ft_puthex(unsigned long ptr);
int		check_len(int n);
void	fill_num(char *res, long int n, int counter);
char	*ft_itoa(int n);
int		count_digit(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_printhexadec(unsigned int n, char format);
int		ft_printpercent(void);
int		ft_printpointer(unsigned long ptr);
int		ft_printstr(char *str);
int		ft_printu(unsigned int u);
int		print_format(va_list arg_ptr, char format);
int		ft_printf(const char *format, ...);
#endif
