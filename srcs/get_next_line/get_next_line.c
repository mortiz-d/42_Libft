/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:47:09 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/05/20 21:24:53 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/get_next_line.h"

// Reading a fd to EOF frees its stash automatically. If you stop before EOF
// (or reuse a fd number), call gnl_clear(fd) to release the leftover stash.
static char	*get_str(char *str);
static char	*get_extra(char *str, char *pin);
static char	*read_buffer(int fd, char *str);
static char	*makenewstr(char *oldstr, int size);

static char	**gnl_get_stash(void)
{
	static char	*stash[GNL_MAX_FD];

	return (stash);
}

void	gnl_clear(int fd)
{
	char	**pin;

	if (fd < 0 || fd >= GNL_MAX_FD)
		return ;
	pin = gnl_get_stash();
	free(pin[fd]);
	pin[fd] = NULL;
}

char	*get_next_line(int fd)
{
	char		**pin;
	char		*str;
	int			tam;

	if (fd < 0 || fd >= GNL_MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (0);
	pin = gnl_get_stash();
	tam = ft_strlen_gnl(pin[fd]);
	if (tam != 0)
	{
		str = ft_calloc_gnl(tam + 1, sizeof(char));
		ft_memcpy_gnl(str, pin[fd], tam);
	}
	else
	{
		free(pin[fd]);
		str = ft_calloc_gnl(tam + 1, sizeof(char));
		pin[fd] = ft_calloc_gnl(tam + 1, sizeof(char));
	}
	str = read_buffer(fd, str);
	pin[fd] = get_extra(str, pin[fd]);
	str = get_str(str);
	return (str);
}

static char	*read_buffer(int fd, char *str)
{
	int		tam;
	int		rd;

	while (ft_strchr_gnl(str, '\n') == 0)
	{
		tam = ft_strlen_gnl(str);
		str = makenewstr(str, (tam + BUFFER_SIZE + 1));
		rd = read(fd, str + tam, BUFFER_SIZE);
		if (rd < 0)
		{
			free(str);
			return (0);
		}
		if (rd == 0)
			break ;
	}
	return (str);
}

static char	*makenewstr(char *oldstr, int size)
{
	char	*newstr;

	newstr = ft_calloc_gnl(size, sizeof(char));
	ft_memcpy_gnl(newstr, oldstr, ft_strlen_gnl(oldstr));
	free (oldstr);
	return (newstr);
}

static char	*get_extra(char *str, char *pin)
{
	char	*extra;
	int		tam;

	extra = NULL;
	if (ft_strchr_gnl(str, '\n') != 0)
	{
		tam = ft_strlen_gnl(ft_strchr_gnl(str, '\n'));
		extra = ft_calloc_gnl(sizeof(char), \
			ft_strlen_gnl(ft_strchr_gnl(str, '\n')) + 1);
		if (extra == 0)
			return (0);
		ft_memcpy_gnl(extra, str + (ft_strlen_gnl(str) - tam + 1), tam);
	}
	free (pin);
	return (extra);
}

static char	*get_str(char *str)
{
	char	*aux;
	int		tam;

	if (ft_strlen_gnl(str) == 0)
	{
		free(str);
		return (0);
	}
	if (ft_strchr_gnl(str, '\n') == 0)
		return (str);
	tam = ft_strlen_gnl(str) - ft_strlen_gnl(ft_strchr_gnl(str, '\n') + 1);
	aux = ft_calloc_gnl(sizeof(char), (tam + 1));
	if (aux == 0)
		return (0);
	aux = ft_memcpy_gnl(aux, str, tam);
	free(str);
	return (aux);
}