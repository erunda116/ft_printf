/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:03:32 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/01 15:20:32 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_puthex(unsigned long ptr)
{
    char *hex = "0123456789abcdef";

    if (ptr >= 16)
        ft_puthex(ptr / 16);
    write(1, &hex[ptr % 16], 1);
}
