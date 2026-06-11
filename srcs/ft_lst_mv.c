/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_mv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:44:41 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/11 19:45:14 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

t_list  *ft_lst_mv_up(t_list *lst)
{
	t_list *aux;
    
    aux = lst;
	if (!aux)
		return NULL;

    aux = aux->prev;
    return aux;
}


t_list  *ft_lst_mv_down(t_list *lst)
{
	t_list *aux;
    
    aux = lst;
	if (!aux)
		return NULL;

    aux = aux->next;

    return aux;
}
