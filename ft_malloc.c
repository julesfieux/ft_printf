/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:52:21 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/11 13:09:48 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_malres(long int num, char *res, int *i)
{
	if (num == 0)
		(*i)++;
	if (num < 0)
	{
		(*i)++;
		num = -num;
	}
	while (num > 0)
	{
		(*i)++;
		num = num / 10;
	}
	if (!(res = malloc(sizeof(char) * ((*i) + 1))))
		return (0);
	res[*i] = '\0';
	(*i)--;
	return (res);
}

char	*ft_malloc_tmp(t_size *size, t_struct *info, char *flag, char *arg)
{
	int i;
	char *tmp;

	i = 0;
	size->nbz = 0;
	if ((size->nbs = ft_nb_space(flag, &i)) < 0)
		return (NULL);
	if (info->letter != 's')
		if (flag[i] == '.')
			if ((size->nbz = ft_nb_zero(flag, (i + 1))) < 0)
				return (NULL);
	size->biggest = size->nbs;
	if (size->nbz > size->biggest)
		size->biggest = size->nbz;
	if (ft_strlen(arg) > size->biggest)
		size->biggest = ft_strlen(arg);
	if (!(tmp = malloc(sizeof(char) * (size->biggest + 1))))
		return (NULL);
	return (tmp);
}
