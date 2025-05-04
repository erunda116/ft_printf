/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:54:20 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/04 18:48:43 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(int num)
{
	int		returning_val;
	char	*str_n;

	returning_val = 0;
	str_n = ft_itoa(num);
	returning_val = ft_printstr(str_n);
	free(str_n);
	return (returning_val);
}
