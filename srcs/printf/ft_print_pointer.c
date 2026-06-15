/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:45:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/15 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

// p
int	ft_write_pointer(int fd, const void *c)
{
	int	written;

	if (!c)
		return (ft_write_string(fd, "(nil)"));
	written = ft_write_string(fd, "0x");
	written += ft_write_nbr_base(fd, (unsigned long)c,
			"0123456789abcdef", 0, '0');
	return (written);
}
