/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:45:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/15 20:38:56 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

// p
int	ft_write_pointer(t_sink *s, const void *c)
{
	int	written;

	if (!c)
		return (ft_write_string(s, "(nil)"));
	written = ft_write_string(s, "0x");
	written += ft_write_nbr_base(s, (unsigned long)c,
			"0123456789abcdef", 0, '0');
	return (written);
}
