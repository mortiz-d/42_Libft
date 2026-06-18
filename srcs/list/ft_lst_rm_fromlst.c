/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rm_fromlst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:36:37 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/11 21:06:49 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

//Removes a content from the list, del function to free contents malloc
void ft_lst_rm_fromlst(t_list **head, t_list *node, void (*del)(void *))
{
    if (!head || !*head || !node)
        return;

    if (*head == node)
        *head = node->next;

    if (node->prev)
        node->prev->next = node->next;

    if (node->next)
        node->next->prev = node->prev;

    if (del)
        del(node->content);

    free(node);
}