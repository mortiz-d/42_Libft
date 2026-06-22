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

#include "printf_internal.h"

static int	write_str(t_sink *sk, const char *str, int width)
{
	int	len;
	int	w;

	if (!str) 
		str = "(null)";
	len = ft_strlen(str);
	w = 0; 
	while (w + len < width)
		w += ft_write_char(sk, ' ');
	return (w + ft_write_string(sk, str));
}

// select format type
static int	dispatch(t_sink *sk, char conv, t_spec *s, va_list *ap)
{
	switch (conv)
	{
		case 'c':
			return (ft_write_char(sk, (char)va_arg(*ap, int)));
		case 's':
			return (write_str(sk, va_arg(*ap, char *), s->width));
		case 'p':
			return (ft_write_pointer(sk, va_arg(*ap, void *)));
		case 'd':
		case 'i':
			return (ft_write_decimal(sk, va_arg(*ap, int), s->width, s->pad));
		case 'u':
			if (s->is_size)
				return (ft_write_nbr_base(sk, va_arg(*ap, size_t),
						"0123456789", s->width, s->pad));
			return (ft_write_nbr_base(sk, va_arg(*ap, unsigned int),
					"0123456789", s->width, s->pad));
		case 'x':
			if (s->is_size)
				return (ft_write_nbr_base(sk, va_arg(*ap, size_t),
						"0123456789abcdef", s->width, s->pad));
			return (ft_write_nbr_base(sk, va_arg(*ap, unsigned int),
					"0123456789abcdef", s->width, s->pad));
		case 'X':
			if (s->is_size)
				return (ft_write_nbr_base(sk, va_arg(*ap, size_t),
						"0123456789ABCDEF", s->width, s->pad));
			return (ft_write_nbr_base(sk, va_arg(*ap, unsigned int),
					"0123456789ABCDEF", s->width, s->pad));
		case '%':
			return (ft_write_char(sk, '%'));
		default:
			return (ft_write_char(sk, '%') + ft_write_char(sk, conv));
	}
}

// to align with the left padding
static int	render(t_sink *sk, t_spec *s, va_list *ap)
{
	t_spec	natural;
	int		n;

	if (!s->left)
		return (dispatch(sk, s->conv, s, ap));
	natural = *s;
	natural.width = 0;
	natural.pad = ' ';
	n = dispatch(sk, s->conv, &natural, ap);
	while (n < s->width)
		n += ft_write_char(sk, ' ');
	return (n);
}

//specifications for conversion , like padding -> %-* ...
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

// Printf motor here we decide if we write a literal char o we formtat
static int	format(t_sink *sk, const char *c, va_list *ap)
{
	t_spec	spec;
	int		total, i;

	total = 0;
	i = 0;
	while ( c [ i ] )
	{
		if (c [ i ] != '%')
		{
			total += ft_write_char(sk ,c[i++]);
			continue ;
		}
		i = parse_spec(c, i + 1 ,&spec ,ap); 
		if (spec.conv == '\0')
			break ;
		total += render(sk , &spec ,ap);
		i++;
	}
	return (total);
}

//printf , a classic , nothing to see here
int	ft_printf(const char *c, ...)
{
	va_list	ap;
	t_sink	sk;
	int		total;

	sink_init(&sk, 1); 
    va_start(ap, c); 
	total = format(&sk, c, &ap);
    va_end(ap);
	return(total);
}

// dprintf , like printf but we choose file descriptor
int	ft_dprintf(int fd, const char *c, ...)
{
	va_list	ap;
	t_sink sk;
	int    total;

	sink_init(&sk, fd);
	va_start(ap, c); 
	total = format(&sk ,c ,&ap); 
	va_end(ap);
	return (total);
}

// asprintf: formats buffer , results is taken by *out , returns , longitude or -1 if memory alloc falilure
int	ft_asprintf(char **out, const char *c, ...)
{
	va_list	ap ;
	t_sink	sk ;
	int		total ;

	sink_init( &sk, -1);
	va_start( ap, c);
	total = format( &sk, c, &ap);
	va_end( ap ); 
	*out = sink_result(&sk);
	if (!*out)
            return (-1);
	return ( total );
}
