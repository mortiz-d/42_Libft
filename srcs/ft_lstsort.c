/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:29:22 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/07 16:32:43 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
    t_list *i;
    t_list *j;
    void *tmp;

    if (!lst || !cmp)
        return;

    i = lst;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (cmp(i->content, j->content) > 0)
            {
                tmp = i->content;
                i->content = j->content;
                j->content = tmp;
            }
            j = j->next;
        }
        i = i->next;
    }
}
