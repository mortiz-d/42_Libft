/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_internal.h"

t_flag *ft_flagnew(char *name, enum flag_type type, t_flag_apply apply,t_flag_not_apply not_apply, va_list args)
{
    t_flag *flag;

    flag = ft_calloc(sizeof(t_flag),1);
    if (!flag)
        return NULL;

    flag->name = ft_strdup(name);
    if (!flag->name)
    {
        free(flag);
        return NULL;
    }

    flag->type = type;
    flag->active = 0;

    flag->apply = apply;
    flag->not_apply = not_apply;

    flag->value.int_value = 0;

    if (type == FLAG_INTEGER)
        flag->value.int_value = va_arg(args, int);

    else if (type == FLAG_RANGE_INTEGER)
    {
        flag->limit_min = va_arg(args, int);
        flag->limit_max = va_arg(args, int);
        flag->value.range.min = 0;
        flag->value.range.max = 0;
    }

    else if (type == FLAG_STRING)
        flag->value.str_value = NULL;

    else if (type == FLAG_STRING_LIST)
        flag->value.list_value = NULL;

    else if (type == FLAG_CHAR)
        flag->value.char_value = 0;

    else if (type == FLAG_BOOLEAN)
        flag->value.bool_value = 0;

    return flag;
}

t_list *set_up_flag(t_list *flag, char *name,enum flag_type type, t_flag_apply apply,t_flag_not_apply not_apply,...)
{
    t_list  *node;
    t_flag  *new_flag;
    va_list args;

    va_start(args, not_apply);
    new_flag = ft_flagnew(name, type, apply, not_apply, args);
    va_end(args);

    if (!new_flag)
        return flag;
    node = ft_lstnew(new_flag);
    if (!node)
        return flag;
    ft_lstadd_front(&flag, node);

    return flag;
}
