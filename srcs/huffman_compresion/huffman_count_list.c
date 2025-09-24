/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_count_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:46:54 by mortiz-d          #+#    #+#             */
/*   Updated: 2025/09/24 00:02:38 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../lib/libft.h"

int ft_count_huffman_list(t_list *lst)
{
    t_list *aux;
    int count;

    count = 0;
    if (!lst)
        return (count);
    aux = lst;

    while (aux)
    {
        count++;
        aux = aux->next;
    }

    return (count);
}