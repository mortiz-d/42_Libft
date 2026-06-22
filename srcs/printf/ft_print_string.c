/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:44:15 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/15 20:38:56 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

// c
int	ft_write_char(t_sink *s, int c)
{
	char	ch;

	ch = (char)c;
	return (sink_write(s, &ch, 1));
}

// s
int	ft_write_string(t_sink *s, const char *c)
{
	int	n;

	if (!c)
		c = "(null)";
	n = 0;
	while (c[n])
		n++;
	return (sink_write(s, c, n));
}
