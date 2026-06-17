/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_internal.h"

void free_flag(void *content)
{
    t_flag *f;

    if (!content)
        return;

    f = (t_flag *)content;

    if (f->name)
        free(f->name);

    if (f->type == FLAG_STRING && f->value.str_value)
        free(f->value.str_value);

    if (f->type == FLAG_STRING_LIST && f->value.list_value)
    {
        ft_lstiter(f->value.list_value, free);
        ft_lstclear(&f->value.list_value);
    }

    free(f);
}

void free_flags(t_list **flags)
{
    if (!flags || !*flags)
        return;

    ft_lstiter(*flags, free_flag);
    ft_lstclear(flags);
}
