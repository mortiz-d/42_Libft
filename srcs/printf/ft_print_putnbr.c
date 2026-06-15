/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:15:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/15 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

static int	base_len(const char *base)
{
	int	n;

	n = 0;
	while (base[n])
		n++;
	return (n);
}


// u / x / X / zu
int	ft_write_nbr_base(int fd, unsigned long n, const char *base, int width,
		char pad)
{
	char	buf[64];
	int		len;
	int		b;
	int		written;

	b = base_len(base);
	len = 0;
	if (n == 0)
		buf[len++] = base[0];
	while (n > 0)
	{
		buf[len++] = base[n % b];
		n /= b;
	}
	written = 0;
	while (written + len < width)
		written += ft_write_char(fd, pad);
	while (len-- > 0)
		written += ft_write_char(fd, buf[len]);
	return (written);
}
