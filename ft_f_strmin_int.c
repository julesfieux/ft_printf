/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_strmin_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:36:48 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/24 13:08:10 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillin_strmin(t_struct *info, char *tmp)
{
	int		i;
	int		len_arg;

	i = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	len_arg = ft_strlen(info->arg);
	if (info->pnt == 1 && info->nbz < len_arg)
		len_arg = info->nbz;
	i = 0;
	while (i < len_arg)
	{
		tmp[i] = info->arg[i];
		i++;
	}
	return (tmp);
}

char	*ft_fillin_int1(t_struct *info, char *tmp, int *i)
{
	int f;

	tmp[info->biggest] = '\0';
	while ((*i) < info->biggest)
		tmp[(*i)++] = ' ';
	(*i)--;
	f = info->nbz;
	while (f > 0)
	{
		tmp[(*i)--] = '0';
		f--;
	}
	if ((*i) < 0)
		(*i) = 0;
	if (info->arg[0] == '-')
	{
		if (ft_strlen(info->arg) > info->nbz)
		{
			while (tmp[(*i)])
				(*i)++;
			(*i) = (*i) - ft_strlen(info->arg);
		}
		tmp[(*i)] = '-';
	}
	return (tmp);
}

char	*ft_fillin_int2(t_struct *info, char *tmp, int *i)
{
	if (info->plus == 1 && info->arg[0] != '-')
	{
		if (ft_strlen(info->arg) > info->nbz)
		{
			while (tmp[(*i)])
				(*i)++;
			(*i) = (*i) - (ft_strlen(info->arg) + 1);
		}
		if (info->arg[0] == '0' && info->pnt == 1 && info->nbs == 0 &&
		info->nbz == 0)
			(*i)++;
		tmp[(*i)] = '+';
	}
	return (tmp);
}

char	*ft_fillin_int3(t_struct *info, char *tmp, int *i, int *f)
{
	if (info->space == 1 && info->plus != 1 && info->arg[0] != '-')
	{
		if (ft_strlen(info->arg) > info->nbz)
		{
			while (tmp[(*i)])
				(*i)++;
			(*i) = (*i) - (ft_strlen(info->arg) + 1);
		}
		if (info->arg[0] == '0' && info->pnt == 1 && info->nbs == 0 &&
		info->nbz == 0)
			(*i)++;
		tmp[(*i)] = ' ';
	}
	while (tmp[(*i)])
		(*i)++;
	(*f) = (*i) - ft_strlen(info->arg);
	(*i) = 0;
	if (info->arg[0] == '-')
	{
		(*f)++;
		(*i)++;
	}
	return (tmp);
}

char	*ft_fillin_int(t_struct *info, char *tmp)
{
	int		i;
	int		f;

	i = 0;
	tmp = ft_fillin_int1(info, tmp, &i);
	tmp = ft_fillin_int2(info, tmp, &i);
	tmp = ft_fillin_int3(info, tmp, &i, &f);
	if (info->space == 1 && info->nbz == 0 && info->arg[0] == '0' &&
	info->pnt == 1)
		return (tmp);
	if (info->arg[0] == '0' && info->pnt == 1 && info->space == 0 &&
	info->star_min == 0)
		return (tmp);
	if (info->arg[0] == '0' && info->pnt == 1 && info->space == 0 &&
	info->star_min == 1 && info->nbs == 0)
	{
		f = 0;
		tmp[1] = '\0';
	}
	while (info->arg[i])
		tmp[f++] = info->arg[i++];
	return (tmp);
}
