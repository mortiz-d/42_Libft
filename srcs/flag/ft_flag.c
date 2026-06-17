/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:20:50 by mortiz-d          #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_internal.h"

//Procesado correcto 1 / Error 0
int process_flags(int argc, char **argv, t_list *flag,struct s_params *params)
{
	int i = 1;
	t_list *aux;
    t_flag *f;
    int ret = 1;

	while (i < argc)
	{
		aux = find_flag(flag,argv[i]);
        //if flag is found we need to extract its data from the argument
		if (aux)
		{
            f = aux->content;
            if (validate_argument(argc,&i,argv,f,flag))
            {
                if (f->apply && !f->apply(f,params))
                    ret = 0;
            }
            else
            {
                ret = 0;
                if (f->not_apply)
                    f->not_apply(f,params);
            }

		}
		i++;
	}
	return ret;
}
