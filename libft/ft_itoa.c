/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:04 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/29 18:45:38 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	n_len;

	n_len = 0;
	if (n == 0)
		n_len++;
	if (n < 0)
	{
		n *= -1;
		n_len++;
	}
	while (n > 0)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

static char	*ft_inttochar(char *dest, int n, int n_len)
{
	if (n == 0)
		*dest = '0';
	if (n < 0)
	{
		*dest = '-';
		n *= -1;
	}
	while (n > 0)
	{
		*(dest + n_len--) = '0' + (n % 10);
		n /= 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		n_len;

	if (n == -2147483648)
	{
		dest = (char *)malloc(sizeof(char) * 12);
		if (!dest)
			return (00);
		ft_strlcpy(dest, "-2147483648", 12);
		return (dest);
	}
	n_len = ft_intlen(n);
	dest = (char *)malloc(sizeof(char) * n_len + 1);
	if (!dest)
		return (00);
	*(dest + n_len--) = '\0';
	dest = ft_inttochar(dest, n, n_len);
	return (dest);
}
