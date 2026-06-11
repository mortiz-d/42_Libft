/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_mv_circular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:56:39 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/11 19:45:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

t_list  *ft_lst_mv_up_circular(t_list *lst)
{
	t_list *aux;
    
    aux = lst;
	if (!aux)
		return NULL;

    aux = aux->prev;
    if (!aux)
        aux = ft_lstlast(lst);
    return aux;
}

t_list  *ft_lst_mv_down_circular(t_list *lst)
{
	t_list *aux;
    
    aux = lst;
	if (!aux)
		return NULL;

    aux = aux->next;
    if (!aux)
        aux = ft_lstfirst(lst);

    return aux;
}