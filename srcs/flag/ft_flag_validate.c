/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_internal.h"

int validate_argument(int argc, int *i, char **argv, t_flag *flag, t_list *flags)
{
    int start = *i;
    int min;
    int max;
    t_list *node;

    if (!flag || !argv || !i)
        return 0;

    switch (flag->type)
    {
        case FLAG_NONE:
        case FLAG_HELP:
            break;

        case FLAG_INTEGER:
            if (*i + 1 >= argc)
                return needs_argument(argv[*i]);

            if (!ft_isnumber(argv[*i + 1]))
                return 0;

            flag->value.int_value = ft_atoi(argv[++(*i)]);
            break;

        case FLAG_STRING:
            if (*i + 1 >= argc)
                return needs_argument(argv[*i]);

            free(flag->value.str_value);
            flag->value.str_value = ft_strdup(argv[++(*i)]);
            break;

        case FLAG_CHAR:
            if (*i + 1 >= argc)
                return needs_argument(argv[*i]);

            if (ft_strlen(argv[*i + 1]) != 1)
                return 0;

            flag->value.char_value = argv[++(*i)][0];
            break;

        case FLAG_BOOLEAN:
        {
            if (*i + 1 >= argc)
                return needs_argument(argv[*i]);

            if (!ft_isnumber(argv[*i + 1]))
                return 0;

            int v = ft_atoi(argv[++(*i)]);
            if (v != 0 && v != 1)
                return 0;

            flag->value.bool_value = v;
            break;
        }

        case FLAG_RANGE_INTEGER:
        {
            if (*i + 2 >= argc)
                return needs_argument(argv[*i]);

            if (!ft_isnumber(argv[*i + 1]) || !ft_isnumber(argv[*i + 2]))
                return 0;

            min = ft_atoi(argv[*i + 1]);
            max = ft_atoi(argv[*i + 2]);

            if (min > max)
            {
                printf("param: invalid range: '%d %d': min must be <= max\n", min, max);
                return 0;
            }
            if (min < flag->limit_min || max > flag->limit_max)
            {
                printf("param: invalid range: '%d %d': out of bounds: %d <= value <= %d\n",
                    min, max, flag->limit_min, flag->limit_max);
                return 0;
            }

            flag->value.range.min = min;
            flag->value.range.max = max;
            *i += 2;
            break;
        }

        case FLAG_STRING_LIST:
            if (*i + 1 >= argc || find_flag(flags, argv[*i + 1]))
                return needs_argument(argv[*i]);

            while (*i + 1 < argc && !find_flag(flags, argv[*i + 1]))
            {
                node = ft_lstnew(ft_strdup(argv[*i + 1]));
                if (!node)
                    return 0;
                ft_lstadd_back(&flag->value.list_value, node);
                (*i)++;
            }
            break;

        default:
            return 0;
    }

    flag->active = 1;
    for (int j = start; j <= *i; j++)
        argv[j] = "\0";

    return 1;
}
