/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:30:50 by mortiz-d          #+#    #+#             */
/*   Updated: 2025/09/23 16:39:33 by mortiz-d         ###   ########.fr       */
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

static t_list *find_character_in_list(t_list *lst, char c)
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

t_list *ft_count_huffman_character(t_list *lst, char c)
{
    t_huffman_count_list *aux_huff;
    t_list *aux;

    if (!lst)
    {
        aux_huff = calloc(1,sizeof(t_huffman_count_list));
        aux_huff->c = c;
        aux_huff->count = 1;
        lst = ft_lstnew(aux_huff);
    }
    else
    {
        aux = find_character_in_list(lst,c);
        if (!aux)
        {
            aux_huff = calloc(1,sizeof(t_huffman_count_list));
            aux_huff->c = c;
            aux_huff->count = 1;
            ft_lstadd_back(&lst,ft_lstnew(aux_huff));
        }
        else
        {
            ((t_huffman_count_list *)aux->content)->count++;

            while (aux->prev)
            {
                if (((t_huffman_count_list *)aux->content)->count > ((t_huffman_count_list *)aux->prev->content)->count)
                {
                    aux_huff = calloc(1,sizeof(t_huffman_count_list));
                    aux_huff->c = ((t_huffman_count_list *)aux->content)->c;
                    aux_huff->count = ((t_huffman_count_list *)aux->content)->count;

                    ((t_huffman_count_list *)aux->content)->c = ((t_huffman_count_list *)aux->prev->content)->c;
                    ((t_huffman_count_list *)aux->content)->count = ((t_huffman_count_list *)aux->prev->content)->count;

                    ((t_huffman_count_list *)aux->prev->content)->c = aux_huff->c;
                    ((t_huffman_count_list *)aux->prev->content)->count = aux_huff->count;
                    free(aux_huff);
                    aux = aux->prev;
                }
                else
                    break;
            
            }
        }
        
    }
    return (lst);
}

