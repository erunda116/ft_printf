/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:03:32 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/01 16:01:44 by miakubov         ###   ########.fr       */
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
int	check_len(int n)
{
	int	n_copy;
	int	counter;

	if (n == 0)
		return (1);
	n_copy = n;
	counter = 0;
	while (n_copy != 0)
	{
		counter++;
		n_copy = n_copy / 10;
	}
	return (counter);
}

void	fill_num(char *res, long int n, int counter)
{
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[counter] = '\0';
	while (n != 0)
	{
		counter--;
		res[counter] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		counter;
    long int    num;
	
    num = n;
	if (num == 0)
	{
		res = malloc(2 * sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	counter = check_len(num);
	if (num < 0)
		counter++;
	res = malloc((counter + 1) * sizeof(char));
	if (!res)
		return (NULL);
	fill_num(res, num, counter);
	return (res);
}