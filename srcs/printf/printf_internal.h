#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include "../../lib/libft.h"

//specification of how to format
typedef struct s_spec
{
	int		width;
	char	pad;
	int		left;
	int		is_size;
	char	conv;
}	t_spec;

// how to handle the result
typedef struct s_sink
{
	int		fd;
	char	*buf;
	size_t	len;
	size_t	cap;
	int		error;
}	t_sink;

void	sink_init(t_sink *s, int fd);
int		sink_write(t_sink *s, const char *data, int n);
char	*sink_result(t_sink *s);
int		ft_write_char(t_sink *s, int c);
int		ft_write_string(t_sink *s, const char *c);
int		ft_write_pointer(t_sink *s, const void *c);
int		ft_write_decimal(t_sink *s, int number, int width, char pad);
int		ft_write_nbr_base(t_sink *s, unsigned long n, const char *base, int width, char pad);

# endif
