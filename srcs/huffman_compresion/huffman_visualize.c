/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_visualize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:50:51 by mortiz-d          #+#    #+#             */
/*   Updated: 2025/09/23 23:50:52 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

void ft_visualize_huffman_list(t_list *lst)
{
    t_list *aux;
    int sum;

    if (!lst)
        return;
    aux = lst;
    sum = 0;

    while (aux)
    {
        sum += ((t_huffman_count_list *)aux->content)->count;
        aux = aux->next;
    }

    aux = lst;
    while (aux)
    {
        printf("%c | %d -> %f\n",((t_huffman_count_list *)aux->content)->c,((t_huffman_count_list *)aux->content)->count, (float)((t_huffman_count_list *)aux->content)->count / (float)sum );
        aux = aux->next;
    }

    return ;
}