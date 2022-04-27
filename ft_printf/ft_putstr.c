/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:37:38 by fefernan          #+#    #+#             */
/*   Updated: 2022/04/27 11:57:14 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, size_t j)
{	
	size_t	n;
	size_t	len;

	n = 0;
	len = 0;
	while (str[len])
		len++;
	if (str == NULL)
	{
		write (1, "NULL", 3);
		j = j + 3;
		return (j);
	}
	while (n < len)
	{
		write (1, (str + n), 1);
		n++;
		j++;
	}
	return (j);
}
