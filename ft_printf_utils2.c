/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:04:08 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/01 16:16:40 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_digit(unsigned int n)
{
    int counter;

    counter = 0;
    while (n != 0)
    {
        n = n / 10;
        counter++;
    }
    return (counter);
}
char *ft_uitoa(unsigned int n)
{
    char *res;
    int len;

    len = count_digit(n);
    res = malloc((len + 1) * sizeof (char));
    if (!res)
        return (NULL);
    res[len] = '\0';
	while (len--)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

