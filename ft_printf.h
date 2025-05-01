/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:27:36 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/01 15:34:10 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printchar(int c);
void	ft_putstr(char *str);
void    ft_puthex(unsigned long ptr);
int ft_printstr(char *str);
int ft_printf(const char *, ...);
#endif
