/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:30:50 by mortiz-d          #+#    #+#             */
/*   Updated: 2025/09/24 17:03:13 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft.h"

t_list *ft_huffman_find(t_list *lst, char c)
{
    t_list *aux;
    if (!lst)
        return (NULL);
    aux = lst;

    while (aux)
    {
        // printf("Comparamos %c - %c\n", c ,((t_huffman_count_list *)aux->content)->c );
        if (((t_huffman_count_list *)aux->content)->c == c)
            return aux;
        aux = aux->next;
    }

    return (NULL);
}

static t_list	*new_huff_node(char c)
{
    t_huffman_count_list	*h;
    t_list					*node;

    h = ft_calloc(1, sizeof(t_huffman_count_list));
    if (!h)
        return (NULL);
    h->c = c;
    h->count = 1;
    node = ft_lstnew(h);
    if (!node)
    {
        free(h);
        return (NULL);
    }
    return (node);
}

static void	huff_bubble_up(t_list *aux)
{
    t_huffman_count_list	*cur;
    t_huffman_count_list	*prv;
    t_huffman_count_list	tmp;

    while (aux->prev)
    {
        cur = aux->content;
        prv = aux->prev->content;
        if (cur->count <= prv->count)
            break ;
        tmp = *prv;
        *prv = *cur;
        *cur = tmp;
        aux = aux->prev;
    }
}

t_list *ft_huffman_add_character(t_list *lst, char c)
{
    t_list	*aux;
    t_list	*node;

    if (!lst)
        return (new_huff_node(c));
    aux = ft_huffman_find(lst, c);
    if (!aux)
    {
        node = new_huff_node(c);
        if (node)
            ft_lstadd_back(&lst, node);
        return (lst);
    }
    ((t_huffman_count_list *)aux->content)->count++;
    huff_bubble_up(aux);
    return (lst);
}

