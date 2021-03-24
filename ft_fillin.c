/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:37:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/24 19:08:27 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillin_othermin1(t_struct *info, char *tmp, int *i, int *f)
{
	if (info->nbz > ft_strlen(info->arg))
		(*f) = (*i) - ft_strlen(info->arg);
	(*i) = 0;
	if (info->letter == 'c' && !info->arg[0])
	{
		info->co = (*f);
		tmp[(*f)++] = ' ';
	}
	else if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X')
	&& info->nbz == 0 && info->pnt == 1 && info->arg[0] == '0' &&
	info->star_min == 0)
	{
		if (info->nbs == 0)
			tmp[(*f)] = 0;
		return (tmp);
	}
	else
	{
		if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
		info->arg[0] != '0' && info->nbz <= ft_strlen(info->arg))
			(*f) = (*f) + 2;
		while (info->arg[(*i)])
			tmp[(*f)++] = info->arg[(*i)++];
	}
	return (tmp);
}

char	*ft_fillin_othermin(t_struct *info, char *tmp)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	i = 0;
	if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
	info->arg[0] != '0')
	{
		tmp[i++] = '0';
		if (info->letter == 'x')
			tmp[i++] = 'x';
		if (info->letter == 'X')
			tmp[i++] = 'X';
		while (i < (info->nbz + 2))
			tmp[i++] = '0';
	}
	else
		while (i < info->nbz)
			tmp[i++] = '0';
	tmp = ft_fillin_othermin1(info, tmp, &i, &f);
	return (tmp);
}

char	*ft_fillin_intmin1(t_struct *info, char *tmp, int *f)
{
	int i;

	i = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	i = 0;
	if (info->arg[0] == '-')
	{
		tmp[i++] = '-';
		info->nbz++;
	}
	else if (info->plus == 1)
	{
		tmp[i++] = '+';
		info->nbz++;
	}
	else if (info->space == 1)
		i++;
	while (i < info->nbz)
		tmp[i++] = '0';
	if (info->nbz > ft_strlen(info->arg))
		(*f) = i - ft_strlen(info->arg);
	return (tmp);
}

char	*ft_fillin_intmin(t_struct *info, char *tmp)
{
	int		i;
	int		f;

	f = 0;
	tmp = ft_fillin_intmin1(info, tmp, &f);
	i = 0;
	if (info->arg[0] == '-')
	{
		f++;
		i++;
	}
	else if (info->plus == 1)
		f++;
	else if (info->space == 1)
		f++;
	if (info->space == 1 && info->nbz == 0 && info->arg[0] == '0'
	&& info->pnt == 1)
		return (tmp);
	if (info->arg[0] == '0' && info->pnt == 1 && info->space == 0 &&
	info->star_min == 0)
		return (tmp);
	while (info->arg[i])
		tmp[f++] = info->arg[i++];
	return (tmp);
}

char	*ft_fillin_all(t_struct *info)
{
	char	*tmp;

	if (info->letter == 'c' && info->arg[0] == '\0' && info->nbs > 0)
		info->nbs--;
	if (!(tmp = ft_malloc_tmp(info)))
		return (NULL);
	if (info->minus == 1)
	{
		if (info->letter == 's')
			tmp = ft_fillin_strmin(info, tmp);
		else if (info->letter == 'i' || info->letter == 'd')
			tmp = ft_fillin_intmin(info, tmp);
		else
			tmp = ft_fillin_othermin(info, tmp);
	}
	else
	{
		if (info->letter == 's')
			tmp = ft_fillin_str(info, tmp, 0);
		else if (info->letter == 'i' || info->letter == 'd')
			tmp = ft_fillin_int(info, tmp);
		else
			tmp = ft_fillin_other(info, tmp);
	}
	return (tmp);
}
