/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_match.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:16:34 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/12 22:43:42 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

t_list *ft_lstfind_match(t_list *lst, int (*f)(void *, void *), void *ctx)
{
	t_list *aux;

	aux = lst;
    while (aux)
    {
        if (f(aux->content, ctx))
            return aux;

        aux = aux->next;
    }

    return NULL;
}
