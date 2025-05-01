/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:27:22 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/01 16:21:16 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_format(va_list arg_ptr, char format)
{
    int returning_val;

    returning_val = 0;
    if (format == 'c')
        returning_val += ft_printchar(va_arg(arg_ptr, int));
    else if (format == 's')
        returning_val += ft_printstr(va_arg(arg_ptr, char *));
    else if (format == 'p')
        returning_val += ft_printpointer(va_arg(arg_ptr, unsigned long));
    else if (format == 'd' || format == 'i')
        returning_val += ft_printdigit(va_arg(arg_ptr, int));
    else if (format == 'u')
        returning_val += ft_printu(va_arg(arg_ptr, unsigned int));
    else if (format == 'x' || format ==  'X')
        returning_val += ft_printhexadec(va_arg(arg_ptr, unsigned int), format);
    else if (format == '%')
        returning_val += ft_printpercent();
    return (returning_val);
}

int ft_printf(const char *format, ...)
{
    va_list arg_ptr;
    int returning_val;
    int i;

    returning_val = 0;
    i = 0;
    va_start(arg_ptr, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
            returning_val += print_format(arg_ptr, format[i + 1]);
        else
            returning_val += ft_printchar(format[i]);
        i++;
    }
    va_end(arg_ptr);
    return (returning_val);
}

int main()
{
    int count;
    int count_or;
    count = ft_printf("test %s", "string");
    count_or = printf("test %s", "string");
    ft_printf("%d", count);
    printf("%d", count_or);

    //pointer
    //char *ptr = NULL;
    //printf("%p", ptr);
}
