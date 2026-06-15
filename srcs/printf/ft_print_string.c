/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:44:15 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/15 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

// c
int	ft_write_char(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

// s
int	ft_write_string(int fd, const char *c)
{
	int	n;

	if (!c)
		c = "(null)";
	n = 0;
	while (c[n])
		n++;
	write(fd, c, n);
	return (n);
}
