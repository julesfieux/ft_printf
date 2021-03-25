/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_str_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:35:32 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/25 10:59:05 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillin_str(t_struct *info, char *tmp, int i)
{
	int		f;

	tmp[info->biggest] = '\0';
	if (info->zero == 1)
		while (i < info->biggest)
			tmp[i++] = '0';
	else
		while (i < info->biggest)
			tmp[i++] = ' ';
	f = i - ft_strlen(info->arg);
	if (info->pnt == 1 && info->nbz < ft_strlen(info->arg))
	{
		f = i - info->nbz;
		i = 0;
		while (i < info->nbz)
			tmp[f++] = info->arg[i++];
	}
	else
	{
		i = 0;
		while (info->arg[i])
			tmp[f++] = info->arg[i++];
	}
	return (tmp);
}

char	*ft_fillin_other1(t_struct *info, char *tmp, int *i)
{
	tmp[info->biggest] = '\0';
	if (info->letter == 'p' && info->nbs <= info->nbz &&
	info->nbs <= ft_strlen(info->arg))
	{
		while ((*i) < 2)
		{
			tmp[(*i)] = info->arg[(*i)];
			(*i)++;
		}
	}
	if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
	info->arg[0] != '0')
	{
		tmp[(*i)++] = '0';
		if (info->letter == 'x')
			tmp[(*i)++] = 'x';
		if (info->letter == 'X')
			tmp[(*i)++] = 'X';
	}
	while ((*i) < info->biggest)
		tmp[(*i)++] = ' ';
	(*i)--;
	return (tmp);
}

char	*ft_fillin_other2(t_struct *info, char *tmp, int *i, int *f)
{
	if (info->nbs <= info->nbz + 2 && info->nbz >= ft_strlen(info->arg) &&
	info->zero == 1 && info->sharp == 1 && info->arg[0] != '0' &&
	(info->letter == 'x' || info->letter == 'X' || info->letter == 'u'))
		info->nbz = info->nbz - 2;
	while (info->nbz > 0)
	{
		tmp[(*i)--] = '0';
		info->nbz--;
	}
	if ((*i) < 0)
		(*i) = 0;
	while (tmp[(*i)] != '\0')
		(*i)++;
	(*f) = (*i) - ft_strlen(info->arg);
	(*i) = 0;
	return (tmp);
}

char	*ft_fillin_other3(t_struct *info, char *tmp, int tmp_nbz, int *f)
{
	int i;

	i = 0;
	if (info->letter == 'p' && tmp_nbz == 0 && info->pnt == 1 &&
	info->arg[0] == '0')
	{
		if (info->star_min == 0)
			(*f)++;
		while ((*f) < info->biggest)
			tmp[(*f)++] = info->arg[i++];
	}
	else
	{
		if (info->letter == 'p' && info->nbs <= tmp_nbz &&
		info->nbs <= ft_strlen(info->arg))
		{
			(*f) = (*f) + 2;
			i = i + 2;
		}
		while (info->arg[i])
			tmp[(*f)++] = info->arg[i++];
	}
	return (tmp);
}

char	*ft_fillin_other(t_struct *info, char *tmp)
{
	int		i;
	int		f;
	int		tmp_nbz;

	i = 0;
	tmp_nbz = info->nbz;
	tmp = ft_fillin_other1(info, tmp, &i);
	tmp = ft_fillin_other2(info, tmp, &i, &f);
	if (info->letter == 'c' && !info->arg[0])
		info->co = f - 1;
	else if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X')
	&& tmp_nbz == 0 && info->pnt == 1 && info->arg[0] == '0' &&
	info->star_min == 0)
	{
		if (info->nbs == 0)
			tmp[f] = 0;
		return (tmp);
	}
	else
		tmp = ft_fillin_other3(info, tmp, tmp_nbz, &f);
	return (tmp);
}
