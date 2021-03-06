/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:45:04 by fefernan          #+#    #+#             */
/*   Updated: 2022/05/09 19:06:23 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	j;
	va_list	ptr;

	i = 0;
	j = 0;
	va_start (ptr, format);
	while (format[i] != 00)
	{
		if (format[i] == '%' && format[i])
		{
			i++;
			j = ft_selector(format[i], ptr, j);
			i++;
		}
		else
		{
			write (1, &format[i], 1);
			i++;
			j++;
		}
	}
	va_end (ptr);
	return (j);
}

size_t	ft_selector(char format, va_list ptr, size_t j)
{
	if (format == 'c')
		j = ft_putchar(va_arg (ptr, int), j);
	else if (format == 's')
		j = ft_putstr(va_arg (ptr, char *), j);
	else if (format == 'd' || format == 'i')
		j = ft_putint (va_arg (ptr, int), j);
	else if (format == 'p')
		j = ft_putptr(va_arg (ptr, void *), j);
	else if (format == 'u')
		j = ft_putuint (va_arg (ptr, unsigned int), j);
	else if (format == 'X')
		j = ft_puthexma (va_arg (ptr, unsigned int), j);
	else if (format == 'x')
		j = ft_puthexmi (va_arg (ptr, unsigned int), j);
	else if (format == '%')
	{
		write (1, "%", 1);
		j = j + 1;
	}
	else
		write (1, "ERROR", 5);
	return (j);
}
