/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelangelortizdelburgo <miguelangelor    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:48:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2024/12/05 19:23:20 by miguelangel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *lst_start, void *(*f)(t_list *, void *))
{
	t_list	*start;
	t_list	*aux;
	t_list	*new;

	start = NULL;
	aux = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst_start, lst->content));
		if (new == NULL)
		{
			ft_lstclear(&start); //In case we try to free all , all allocations inside t_list will be left as leaks
			return (NULL);
		}
		new->prev = aux;
		if (aux != NULL)
			aux->next = new;
		else
			start = new;
		aux = new;
		lst = lst->next;
	}
	return (start);
}
