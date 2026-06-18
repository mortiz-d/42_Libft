/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelangelortizdelburgo <miguelangelor    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:59:30 by mortiz-d          #+#    #+#             */
/*   Updated: 2024/12/05 19:23:20 by miguelangel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*aux1;
	unsigned long	aux2;

	aux1 = (char *)s;
	aux2 = 0;
	while (aux2 < n)
	{
		if ((unsigned char)aux1[aux2] == (unsigned char)c)
			return (aux1 + aux2);
		aux2++;
	}
	return (0);
}
