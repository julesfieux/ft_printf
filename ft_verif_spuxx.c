/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_spuxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:51:16 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/19 10:51:47 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_verif_nbz_spuxx(t_struct *info, int *len_flag, int *i, char **f_ref)
{
	char *flag;

	flag = *f_ref;
	if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X' ||
	info->letter == 's') && info->l > 2)
		return (-1);
	if (info->letter == 'p' && info->l > 0)
		return (-1);
	if (info->data[info->cnt - (*i)] == '*')
	{
		flag[(*len_flag)--] = info->data[info->cnt - (*i)];
		(*i)++;
	}
	else
	{
		while ((*len_flag) >= 0 && info->data[info->cnt - (*i)] >= '0' &&
		info->data[info->cnt - (*i)] <= '9')
		{
			flag[(*len_flag)--] = info->data[info->cnt - (*i)];
			(*i)++;
		}
	}
	*f_ref = flag;
	return (0);
}

char	*ft_verif_nbs_spuxx(t_struct *info, int *len_flag, int *i, char *flag)
{
	if (info->data[info->cnt - (*i)] == '.')
	{
		flag[(*len_flag)--] = info->data[info->cnt - (*i)];
		(*i)++;
		if (info->data[info->cnt - (*i)] == '*')
		{
			flag[(*len_flag)--] = info->data[info->cnt - (*i)];
			(*i)++;
		}
		else
		{
			while ((*len_flag) >= 0 && info->data[info->cnt - (*i)] >= '0' &&
			info->data[info->cnt - (*i)] <= '9')
			{
				flag[(*len_flag)--] = info->data[info->cnt - (*i)];
				(*i)++;
			}
		}
	}
	return (flag);
}

int		ft_verif_spuxx(char **flag_ref, int len_flag, t_struct *info, int i)
{
	char	*flag;

	flag = *flag_ref;
	if (ft_verif_nbz_spuxx(info, &len_flag, &i, &flag) < 0)
		return (-1);
	ft_verif_nbs_spuxx(info, &len_flag, &i, flag);
	while (len_flag >= 0 && (info->data[info->cnt - i] == '-'
	|| info->data[info->cnt - i] == '0' || info->data[info->cnt - i] == '#' ||
	info->data[info->cnt - i] == 'l'))
	{
		if (info->data[info->cnt - i] == '#')
			i++;
		else if (info->data[info->cnt - i] == '0')
			i++;
		else
		{
			flag[len_flag--] = info->data[info->cnt - i];
			i++;
		}
	}
	if (len_flag >= 0)
		return (-1);
	*flag_ref = flag;
	return (0);
}
