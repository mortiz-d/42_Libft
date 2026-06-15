/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:35:42 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/15 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

static int	num_len(unsigned long n, int b)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)b)
	{
		n /= b;
		len++;
	}
	return (len);
}

// d / i -> %05d | %5d
int	ft_write_decimal(int fd, int number, int width, char pad)
{
	unsigned long	u;
	int				sign;
	int				written;

	sign = (number < 0);
	if (sign)
		u = (unsigned long)(-(long)number);
	else
		u = (unsigned long)number;
	written = 0;
	if (pad == ' ')
	{
		while (written + num_len(u, 10) + sign < width)
			written += ft_write_char(fd, ' ');
		if (sign)
			written += ft_write_char(fd, '-');
		return (written + ft_write_nbr_base(fd, u, "0123456789", 0, '0'));
	}
	if (sign)
		written += ft_write_char(fd, '-');
	return (written + ft_write_nbr_base(fd, u, "0123456789", width - sign, '0'));
}
