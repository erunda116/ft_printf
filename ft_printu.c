/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:54:53 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/01 16:03:26 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printu(unsigned int u)
{
    int returning_val;
    char *str_n;

    returning_val = 0;
    str_n = ft_uitoa(u);
    returning_val = ft_printstr(str_n);
	free(str_n);
	return (returning_val);
}
