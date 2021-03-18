/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:52:21 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/18 11:33:11 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_malres(long long int num, char *res, int *i)
{
	long long lim;

	lim = -9223372036854775807;
	if (num == 0)
		(*i)++;
	if (num == (lim - 1))
		*i = 20;
	else
	{
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
	}
	if (!(res = malloc(sizeof(char) * ((*i) + 1))))
		return (0);
	res[*i] = '\0';
	(*i)--;
	return (res);
}

char	*ft_umalres(unsigned long long int num, char *res, int *i)
{
	if (num == 0)
		(*i)++;
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

int		ft_malloc_tmp1(t_struct *info, int len_arg)
{
	len_arg = ft_strlen(info->arg);
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
		{
			if (len_arg > info->nbs)
				info->biggest = len_arg;
		}
	}
	return (len_arg);
}

void	ft_malloc_tmp2(t_struct *info, int len_arg)
{
	if (info->letter == 'i' || info->letter == 'd')
	{
		if (info->arg[0] == '-' && info->nbs <= info->nbz &&
		info->nbz > len_arg && info->pnt == 1)
			info->biggest++;
		if (len_arg > info->nbs && len_arg > info->nbz &&
		info->arg[0] == '0' && info->pnt == 1 && info->space == 0)
			info->biggest--;
		if (info->plus == 1 && len_arg >= info->nbs
		&& info->arg[0] != '-')
			info->biggest++;
		if (info->space == 1 && info->arg[0] != '-' && info->plus == 0 &&
		info->zero == 0 && (len_arg >= info->nbs ||
		info->nbz >= info->nbs))
		{
			if (info->pnt == 0)
				info->biggest++;
			else if (info->nbz > 0)
				info->biggest++;
		}
	}
}

void	ft_malloc_tmp3(t_struct *info, int len_arg)
{
	if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
	info->arg[0] != '0')
	{
		if (info->nbs <= info->nbz && info->nbs <= len_arg)
			info->biggest = info->biggest + 2;
		else if (info->nbs <= info->nbz + 2 && info->nbz >= len_arg)
			info->biggest = info->biggest + ((info->nbz + 2) - info->nbs);
		else if (info->nbs <= len_arg + 2 && len_arg >= info->nbz)
			info->biggest = info->biggest + ((len_arg + 2) - info->nbs);
	}
	if (info->letter == 'p')
	{
		if (info->nbz > (info->nbs - 2) && info->nbz < info->nbs &&
		info->nbz > (len_arg - 2))
			info->biggest = info->biggest + 1;
		else if (info->nbz > (info->nbs - 2) && info->nbz > (len_arg - 2))
			info->biggest = info->biggest + 2;
	}
	if (info->letter == 'p' && info->nbz == 0 && info->pnt == 1 &&
	info->arg[0] == '0' && info->nbs < len_arg)
		info->biggest--;
}

char	*ft_malloc_tmp(t_struct *info)
{
	char	*tmp;
	int		len_arg;

	len_arg = 0;
	len_arg = ft_malloc_tmp1(info, len_arg);
	if (info->letter != 's')
	{
		if (info->nbz > info->biggest)
			info->biggest = info->nbz;
		if (len_arg > info->biggest)
			info->biggest = len_arg;
		ft_malloc_tmp2(info, len_arg);
		ft_malloc_tmp3(info, len_arg);
		if (info->letter == 'c' && !info->arg[0])
			info->biggest++;
	}
	if (!(tmp = malloc(sizeof(char) * (info->biggest + 1))))
		return (NULL);
	return (tmp);
}
