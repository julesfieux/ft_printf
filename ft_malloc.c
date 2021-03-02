/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:52:21 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/02 10:17:04 by jfieux           ###   ########.fr       */
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

char	*ft_malloc_tmp(t_size *size, t_struct *info, char *arg)
{
	char *tmp;

	size->biggest = size->nbs;
	if (info->letter == 's')
	{
		if (size->pnt == 1)
		{
			if (size->nbz < ft_strlen(arg) && size->nbz > size->nbs)
				size->biggest = size->nbz;
			else if (ft_strlen(arg) > size->nbs && size->nbz > size->nbs)
				size->biggest = ft_strlen(arg);
		}
		else
			if (ft_strlen(arg) > size->nbs)
				size->biggest = ft_strlen(arg);
	}
	else
	{
		if (size->nbz > size->biggest)
			size->biggest = size->nbz;
		if (ft_strlen(arg) > size->biggest)
			size->biggest = ft_strlen(arg);
		if (info->letter == 'i' || info->letter == 'd')
		{
			if (arg[0] == '-' && size->nbs <= size->nbz)
			size->biggest++;
		}
		if (info->letter == 'c' && !arg[0])
			size->biggest++;
		if (ft_strlen(arg) > size->nbs && ft_strlen(arg) > size->nbz && 
		(info->letter == 'd' || info->letter == 'i') && arg[0] == '0' &&
		size->pnt == 1)
			size->biggest--;
	}
	if (!(tmp = malloc(sizeof(char) * (size->biggest + 1))))
		return (NULL);
	return (tmp);
}
