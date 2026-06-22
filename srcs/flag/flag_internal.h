/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:45:34 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/17 18:46:01 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_INTERNAL_H
# define FLAG_INTERNAL_H

# include "../../lib/libft.h"
# include "../../lib/flag.h"

t_flag	*ft_flagnew(char *name, enum flag_type type, t_flag_apply apply,
			t_flag_not_apply not_apply, va_list args);
int		needs_argument(char *c);
int		is_exact_flag_word(char *str, char *cmp);
t_list	*find_flag(t_list *flag, char *c);
int		validate_argument(int argc, int *i, char **argv, t_flag *flag,
			t_list *flags);

# endif
