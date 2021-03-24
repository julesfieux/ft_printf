/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:16:58 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/24 13:40:25 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		str_len_flag1(t_struct *info, int len_flag)
{
	info->cnt++;
	len_flag = info->cnt;
	info->plus = 0;
	info->minus = 0;
	info->pnt = 0;
	while (ft_isletter(info->data[info->cnt]) != 1 && info->data[info->cnt])
	{
		if (info->data[info->cnt] == '.')
			info->pnt = 1;
		info->cnt++;
	}
	return (len_flag);
}

int		str_len_flag2(t_struct *info, int len_flag)
{
	while (info->data[info->cnt] == '0' || info->data[info->cnt] == '-' ||
	info->data[info->cnt] == '+' || info->data[info->cnt] == ' ' ||
	info->data[info->cnt] == 'l')
	{
		if (info->data[info->cnt] == '-')
			info->minus = 1;
		if (info->data[info->cnt] == '+')
			info->plus = 1;
		if (info->data[info->cnt] == ' ')
			info->space = 1;
		if (info->data[info->cnt] == 'l')
			(info->l)++;
		if (info->data[info->cnt] != '0' || info->data[info->cnt + 1] == '.')
			len_flag++;
		else
		{
			if (info->pnt == 0 || info->letter == 's' || info->nbz == 0)
				info->zero = 1;
		}
		info->cnt++;
	}
	return (len_flag);
}

int		str_len_flag(t_struct *info)
{
	int len_flag;

	len_flag = 0;
	len_flag = str_len_flag1(info, len_flag);
	if (!info->data[info->cnt])
		return (-1);
	info->letter = info->data[info->cnt];
	info->cnt = len_flag;
	len_flag = 0;
	if (info->data[info->cnt] == '#')
	{
		info->sharp = 1;
		info->cnt++;
	}
	len_flag = str_len_flag2(info, len_flag);
	while (ft_isletter(info->data[info->cnt]) != 1 && info->data[info->cnt])
	{
		info->cnt++;
		len_flag++;
	}
	return (len_flag);
}

int		ft_z_co(t_struct *info)
{
	int i;
	int *tmp;

	i = 0;
	while (info->z_co[i] >= 0)
		i++;
	if (!(tmp = malloc(sizeof(int) * (i + 2))))
		return (0);
	i = 0;
	while (info->z_co[i] >= 0)
	{
		tmp[i] = info->z_co[i];
		i++;
	}
	tmp[i] = info->co + ft_strlen(info->res);
	tmp[i + 1] = -1;
	free(info->z_co);
	info->z_co = tmp;
	return (1);
}
