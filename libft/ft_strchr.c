/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:37:08 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/10 18:22:58 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s != cc && *s != 00)
		s++;
	if (*s == cc)
		return ((char *)s);
	return (0);
}
