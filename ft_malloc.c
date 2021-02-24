/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:52:21 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/24 11:31:12 by jfieux           ###   ########.fr       */
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
	int s;
	char *tmp;

	i = 0;
	s = 0;
	size->nbz = 0;
	while (flag[s] == '-' || flag[s] == '+')
		s++;
	if ((size->nbs = ft_nb_space(flag, &i, s)) < 0)
		return (NULL);
	size->biggest = size->nbs;
	if (info->letter == 's')
	{
		if (flag[i + s] == '.')
		{
			size->pnt = 1;
printf("2\n");
			if ((size->nbz = ft_nb_zero(flag, (i + 1), s)) < 0)
				return (NULL);
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
		if (flag[i + s] == '.')
			if ((size->nbz = ft_nb_zero(flag, (i + 1), s)) < 0)
				return (NULL);
		if (size->nbz > size->biggest)
			size->biggest = size->nbz;
		if (ft_strlen(arg) > size->biggest)
			size->biggest = ft_strlen(arg);
		if ((info->letter == 'i' || info->letter == 'd') && arg[0] == '-'
		&& size->nbs <= size->nbz && size->nbs <= ft_strlen(arg))
			size->biggest++;
	}
	printf("size->biggest = %d\n", size->biggest);
	if (!(tmp = malloc(sizeof(char) * (size->biggest + 1))))
		return (NULL);
	return (tmp);
}
