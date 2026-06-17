/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_internal.h"

int needs_argument(char *c)
{
	printf ("param : %s requires an argument\n",c);
	return (0);
}

int is_exact_flag_word(char *str, char *cmp)
{
	if (ft_strncmp(str,cmp,ft_strlen(cmp)) == 0 && ft_strlen(str) == ft_strlen(cmp))
		return (1);
	return (0);
}

t_list *find_flag(t_list *flag, char *c)
{
	t_list *aux;
    t_flag *f;

	aux = flag;
	while (aux)
	{
		f = (t_flag *)aux->content;

		if (is_exact_flag_word(f->name, c))
			return aux;

		aux = aux->next;
	}
	return NULL;
}
