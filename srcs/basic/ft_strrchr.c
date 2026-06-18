/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:10:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/15 15:07:23 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char		*aux1;
	unsigned long	aux2;

	aux1 = s;
	aux2 = 0;
	while (aux1[aux2] != '\0')
		aux2++;
	while (aux2 > 0 )
	{
		if ((unsigned char)aux1[aux2] == (unsigned char)c)
			return (&((char *)aux1)[aux2]);
		aux2--;
	}	
	if ((unsigned char)aux1[aux2] == (unsigned char)c)
		return (&((char *)aux1)[aux2]);
	return (0);
}
