/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:52:21 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/03 10:57:29 by jfieux           ###   ########.fr       */
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

char	*ft_malloc_tmp(t_struct *info, char *arg)
{
	char *tmp;
	int		len_arg;

	len_arg = ft_strlen(arg);
	info->biggest = info->nbs;
	if (info->letter == 's')
	{
		if (info->pnt == 1)
		{
			if (info->nbz < len_arg && info->nbz > info->nbs)
				info->biggest = info->nbz;
			else if (len_arg > info->nbs && info->nbz > info->nbs)
				info->biggest = len_arg;
		}
		else
			if (len_arg > info->nbs)
				info->biggest = len_arg;
	}
	else
	{
		if (info->nbz > info->biggest)
			info->biggest = info->nbz;
		if (len_arg > info->biggest)
			info->biggest = len_arg;
		if (info->letter == 'i' || info->letter == 'd')
		{
			if (arg[0] == '-' && info->nbs < info->nbz)
			info->biggest++;
		}
		if (info->letter == 'c' && !arg[0])
			info->biggest++;
		if (len_arg > info->nbs && len_arg > info->nbz && 
		(info->letter == 'd' || info->letter == 'i') && arg[0] == '0' &&
		info->pnt == 1)
			info->biggest--;
	}
	if (!(tmp = malloc(sizeof(char) * (info->biggest + 1))))
		return (NULL);
	return (tmp);
}
