/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miakubov <miakubov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:27:22 by miakubov          #+#    #+#             */
/*   Updated: 2025/05/04 19:37:40 by miakubov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list arg_ptr, char format)
{
	int	returning_val;

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
	else if (format == 'x' || format == 'X')
		returning_val += ft_printhexadec(va_arg(arg_ptr, unsigned int), format);
	else if (format == '%')
		returning_val += ft_printpercent();
	return (returning_val);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		returning_val;
	int		i;

	returning_val = 0;
	i = 0;
	va_start(arg_ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			returning_val += print_format(arg_ptr, format[i + 1]);
			i++;
		}
		else
			returning_val += ft_printchar(format[i]);
		i++;
	}
	va_end(arg_ptr);
	return (returning_val);
}
/*
#include <stdio.h>
#include <limits.h>
int main()
{
    int count;
    int count_original;
    char *ptr = "tester";
    char *ptr2 = 0xFFFFFFFF0;
    char *ptrNull = NULL;

    count = ft_printf("This is char %c, we print it\n", 't');
    count_original = printf("This is char %c, we print it\n", 't');
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is string %s, we print it\n", "tester");
    count_original = printf("This is string %s, we print it\n", "tester");
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is string NULL %s, we print it\n", ptrNull);
    count_original = printf("This is string NULL %s, we print it\n", ptrNull);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is pointer %p, we print it\n", ptr);
    count_original = printf("This is pointer %p, we print it\n", ptr);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is pointer NULL %p, we print it\n", ptrNull);
    count_original = printf("This is pointer NULL %p, we print it\n", ptrNull);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is number %d, we print it\n", 12345);
    count_original = printf("This is number %d, we print it\n", 12345);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is number i %i, we print it\n", 98765);
    count_original = printf("This is number i %i, we print it\n", 98765);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is unsigned integer %u, we print it\n", 0);
    count_original = printf("This is unsigned integer %u, we print it\n", 0);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("edges %u, we print it\n", 55555);
    count_original = printf("edges %u, we print it\n", 55555);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("hexadecimal %x, we print it\n", 42);
    count_original = printf("hexadecimal %x, we print it\n", 42);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("hexadecimal big %X, we print it\n", 42);
    count_original = printf("hexadecimal big %X, we print it\n", 42);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");

    count = ft_printf("This is percent %%, we print it\n");
    count_original = printf("This is percent %%, we print it\n");
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

     ft_printf("\n================\n");

    count = ft_printf("This is percents %%%%, we print it\n");
    count_original = printf("This is percents %%%%, we print it\n");
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

    ft_printf("\n================\n");
    count = ft_printf("%%\n");
    count_original = printf("%%\n");
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

     ft_printf("\n================\n");

    count = ft_printf("%%%p\n", ptr);
    count_original = printf("%%%p\n", ptr);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);

     ft_printf("\n================\n");

    count = ft_printf("%X\n", ptr2);
    count_original = printf("%X\n", ptr2);
    ft_printf("Lenght of count = %d\n", count);
    printf("Lenght of count = %d\n", count_original);
}*/