/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:53:26 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/15 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

static int	dispatch(int fd, char conv, int width, char pad, int is_size,
		va_list ap)
{
	switch (conv)
	{
		case 'c':
			return (ft_write_char(fd, (char)va_arg(ap, int)));
		case 's':
			return (ft_write_string(fd, va_arg(ap, char *)));
		case 'p':
			return (ft_write_pointer(fd, va_arg(ap, void *)));
		case 'd':
		case 'i':
			return (ft_write_decimal(fd, va_arg(ap, int), width, pad));
		case 'u':
			if (is_size)
				return (ft_write_nbr_base(fd, va_arg(ap, size_t),
						"0123456789", width, pad));
			return (ft_write_nbr_base(fd, va_arg(ap, unsigned int),
					"0123456789", width, pad));
		case 'x':
			return (ft_write_nbr_base(fd, va_arg(ap, unsigned int),
					"0123456789abcdef", width, pad));
		case 'X':
			return (ft_write_nbr_base(fd, va_arg(ap, unsigned int),
					"0123456789ABCDEF", width, pad));
		case '%':
			return (ft_write_char(fd, '%'));
		default:
			return (ft_write_char(fd, '%') + ft_write_char(fd, conv));
	}
}

static int	format_fd(int fd, const char *c, va_list ap)
{
	int		total;
	int		i;
	int		width;
	char	pad;

	total = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] != '%')
		{
			total += ft_write_char(fd, c[i++]);
			continue ;
		}
		i++;
		pad = ' ';
		if (c[i] == '0')
		{
			pad = '0';
			i++;
		}
		width = 0;
		while (c[i] >= '0' && c[i] <= '9')
			width = width * 10 + (c[i++] - '0');
		if (c[i] == '\0')
			break ;
		if (c[i] == 'z')
		{
			total += dispatch(fd, c[i + 1], width, pad, 1, ap);
			i += 2;
		}
		else
			total += dispatch(fd, c[i++], width, pad, 0, ap);
	}
	return (total);
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		total;

	va_start(ap, c);
	total = format_fd(1, c, ap);
	va_end(ap);
	return (total);
}

int	ft_dprintf(int fd, const char *c, ...)
{
	va_list	ap;
	int		total;

	va_start(ap, c);
	total = format_fd(fd, c, ap);
	va_end(ap);
	return (total);
}
