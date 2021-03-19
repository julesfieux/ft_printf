/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:46:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/19 10:51:39 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_verif_nbs_c(t_struct *info, char *flag, int *len_flag, int *i)
{
	if (info->data[info->cnt - (*i)] == '.')
	{
		flag[(*len_flag)] = info->data[info->cnt - (*i)];
		(*len_flag)--;
		(*i)++;
	}
	if (info->data[info->cnt - (*i)] == '*')
	{
		flag[(*len_flag)] = info->data[info->cnt - (*i)];
		(*len_flag)--;
		(*i)++;
	}
	else
	{
		while (info->data[info->cnt - (*i)] <= '9' &&
		info->data[info->cnt - (*i)] >= '0')
		{
			flag[(*len_flag)] = info->data[info->cnt - (*i)];
			(*len_flag)--;
			(*i)++;
		}
	}
	return (flag);
}

int		ft_verif_c(char **flag_ref, int len_flag, t_struct *info)
{
	int		i;
	char	*flag;

	flag = *flag_ref;
	i = 1;
	if (info->letter == 'c' && info->l > 2)
		return (-1);
	flag = ft_verif_nbs_c(info, flag, &len_flag, &i);
	while (info->data[info->cnt - i] == '-')
	{
		flag[len_flag] = info->data[info->cnt - i];
		len_flag--;
		i++;
	}
	if (len_flag >= 0)
		return (-1);
	*flag_ref = flag;
	return (0);
}

int		ft_verif_nbz_id(t_struct *info, int *len_flag, char **flag_ref, int *i)
{
	char *flag;

	flag = *flag_ref;
	if ((info->letter == 'i' || info->letter == 'd') && info->l > 2)
		return (-1);
	if (info->letter == '%' && info->l > 0)
		return (-1);
	if (info->data[info->cnt - (*i)] == '*')
	{
		flag[(*len_flag)--] = info->data[info->cnt - (*i)];
		(*i)++;
	}
	else
	{
		while (info->data[info->cnt - (*i)] >= '0' &&
		info->data[info->cnt - (*i)] <= '9' && (*len_flag) >= 0)
		{
			flag[(*len_flag)--] = info->data[info->cnt - (*i)];
			(*i)++;
		}
	}
	*flag_ref = flag;
	return (0);
}

char	*ft_verif_nbs_id(t_struct *info, char *flag, int *i, int *len_flag)
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

int		ft_verif_id(char **flag_ref, int len_flag, t_struct *info, int i)
{
	char	*flag;

	flag = *flag_ref;
	if (ft_verif_nbz_id(info, &len_flag, &flag, &i) < 0)
		return (-1);
	flag = ft_verif_nbs_id(info, flag, &i, &len_flag);
	while (len_flag >= 0 && (info->data[info->cnt - i] == '-' ||
	info->data[info->cnt - i] == ' ' || info->data[info->cnt - i] == '+' ||
	info->data[info->cnt - i] == '0' || info->data[info->cnt - i] == 'l'))
	{
		if (info->data[info->cnt - i] == '0')
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
