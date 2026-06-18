/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:53:26 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/16 18:45:38 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

typedef struct s_spec
{
	int		width;
	char	pad;
	int		left;
	int		is_size;
	char	conv;
}	t_spec;

static int	write_str(int fd, const char *str, int width)
{
	int	len;
	int	w;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	w = 0;
	while (w + len < width)
		w += ft_write_char(fd, ' ');
	return (w + ft_write_string(fd, str));
}

static int	dispatch(int fd, char conv, t_spec *s, va_list *ap)
{
	switch (conv)
	{
		case 'c':
			return (ft_write_char(fd, (char)va_arg(*ap, int)));
		case 's':
			return (write_str(fd, va_arg(*ap, char *), s->width));
		case 'p':
			return (ft_write_pointer(fd, va_arg(*ap, void *)));
		case 'd':
		case 'i':
			return (ft_write_decimal(fd, va_arg(*ap, int), s->width, s->pad));
		case 'u':
			if (s->is_size)
				return (ft_write_nbr_base(fd, va_arg(*ap, size_t),
						"0123456789", s->width, s->pad));
			return (ft_write_nbr_base(fd, va_arg(*ap, unsigned int),
					"0123456789", s->width, s->pad));
		case 'x':
			if (s->is_size)
				return (ft_write_nbr_base(fd, va_arg(*ap, size_t),
						"0123456789abcdef", s->width, s->pad));
			return (ft_write_nbr_base(fd, va_arg(*ap, unsigned int),
					"0123456789abcdef", s->width, s->pad));
		case 'X':
			if (s->is_size)
				return (ft_write_nbr_base(fd, va_arg(*ap, size_t),
						"0123456789ABCDEF", s->width, s->pad));
			return (ft_write_nbr_base(fd, va_arg(*ap, unsigned int),
					"0123456789ABCDEF", s->width, s->pad));
		case '%':
			return (ft_write_char(fd, '%'));
		default:
			return (ft_write_char(fd, '%') + ft_write_char(fd, conv));
	}
}

static int	render(int fd, t_spec *s, va_list *ap)
{
	t_spec	natural;
	int		n;

	if (!s->left)
		return (dispatch(fd, s->conv, s, ap));
	natural = *s;
	natural.width = 0;
	natural.pad = ' ';
	n = dispatch(fd, s->conv, &natural, ap);
	while (n < s->width)
		n += ft_write_char(fd, ' ');
	return (n);
}

static int	parse_spec(const char *c, int i, t_spec *s, va_list *ap)
{
	s->pad = ' ';
	s->left = 0;
	s->is_size = 0;
	while (c[i] == '-' || c[i] == '0')
	{
		if (c[i] == '-')
			s->left = 1;
		else
			s->pad = '0';
		i++;
	}
	if (c[i] == '*')
	{
		s->width = va_arg(*ap, int);
		if (s->width < 0)
		{
			s->left = 1;
			s->width = -s->width;
		}
		i++;
	}
	else
	{
		s->width = 0;
		while (c[i] >= '0' && c[i] <= '9')
			s->width = s->width * 10 + (c[i++] - '0');
	}
	if (c[i] == 'z')
	{
		s->is_size = 1;
		i++;
	}
	s->conv = c[i];
	return (i);
}

static int	format_fd(int fd, const char *c, va_list *ap)
{
	t_spec	spec;
	int		total;
	int		i;

	total = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] != '%')
		{
			total += ft_write_char(fd, c[i++]);
			continue ;
		}
		i = parse_spec(c, i + 1, &spec, ap);
		if (spec.conv == '\0')
			break ;
		total += render(fd, &spec, ap);
		i++;
	}
	return (total);
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		total;

	va_start(ap, c);
	total = format_fd(1, c, &ap);
	va_end(ap);
	return (total);
}

int	ft_dprintf(int fd, const char *c, ...)
{
	va_list	ap;
	int		total;

	va_start(ap, c);
	total = format_fd(fd, c, &ap);
	va_end(ap);
	return (total);
}
