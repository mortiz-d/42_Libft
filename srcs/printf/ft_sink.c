/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sink.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:20:12 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/22 21:15:15 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

void	sink_init(t_sink *s, int fd)
{
	s->fd = fd;
	s->buf = NULL;
	s->len = 0;
	s->cap = 0;
	s->error = 0;
}

// expand the buffersink to allocate needed bytes ('\0' included)
static int	sink_grow(t_sink *s, size_t need)
{
	size_t	ncap;
	char	*nbuf;

	ncap = s->cap;
	if (ncap == 0)
		ncap = 32;
	while (ncap < need)
		ncap *= 2;
	nbuf = malloc(ncap);
	if (!nbuf)
	{
		s->error = 1;
		return (0);
	}
	if (s->buf)
	{
		ft_memcpy(nbuf, s->buf, s->len);
		free(s->buf);
	}
	s->buf = nbuf;
	s->cap = ncap;
	return (1);
}

// write n bytes to dst, write into a descriptor if fd>=0 or the buffer if fd<0
int	sink_write(t_sink *s, const char *data, int n)
{
	if (s->fd >= 0)
	{
		write(s->fd, data, n);
		return (n);
	}
	if (s->error)
		return (n);
	if (s->len + (size_t)n + 1 > s->cap && !sink_grow(s, s->len + n + 1))
		return (n);
	ft_memcpy(s->buf + s->len, data, n);
	s->len += n;
	return (n);
}

//close buffer (mode asprintf: '\0' good end or NULL if failed)
char	*sink_result(t_sink *s)
{
	if (s->error)
	{
		free(s->buf);
		return (NULL);
	}
	if (!s->buf)
		return (ft_calloc(1, 1));
	s->buf[s->len] = '\0';
	return (s->buf);
}
