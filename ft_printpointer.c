/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:53:48 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/01 15:44:42 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printpointer(void *ptr)
{
    unsigned long address;
    int i;

    if (!ptr)
	{
		ft_putstr("0x0"); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		return (3);
	}
    address = (unsigned long)ptr;

    ft_putstr("0x");
    ft_puthex(address);

    i = 2;
    while (address)
    {
        address /= 16;
        i++;
    }
    return (i);
}
