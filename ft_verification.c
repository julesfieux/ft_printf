/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:46:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/26 11:11:41 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_verif_cp(char **flag_ref, int len_flag, t_struct *info)
{
	int i;
	char	*flag;

	flag = *flag_ref;
	i = 1;
	if (info->data[info->cnt - i] == '.')
	{
		flag[len_flag] = info->data[info->cnt - i];
		len_flag--;
		i++;
	}
	if (info->data[info->cnt - i] == '*')
	{
		flag[len_flag] = info->data[info->cnt - i];
		len_flag--;
		i++;
	}
	else
	{
		while (info->data[info->cnt - i] <= '9' && info->data[info->cnt - i] >= '0')
		{
			flag[len_flag] = info->data[info->cnt - i];
			len_flag--;
			i++;
		}
	}
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

int		ft_verif_id(char **flag_ref, int len_flag, t_struct *info, int i)
{	
	char	*flag;

	flag = *flag_ref;
	if (info->data[info->cnt - i] == '*')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	else
	{
		while (info->data[info->cnt - i] >= '0' && info->data[info->cnt - i] <= '9')
		{
			flag[len_flag--] = info->data[info->cnt - i];
			i++;
		}
	}
	if (info->data[info->cnt - i] == '.')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
		if (info->data[info->cnt - i] == '*')
		{
			flag[len_flag--] = info->data[info->cnt - i];
			i++;
		}
		else
		{
			while (info->data[info->cnt - i] >= '0' && info->data[info->cnt - i] <= '9')
			{
				flag[len_flag--] = info->data[info->cnt - i];
				i++;
			}
		}
	}
	while (len_flag >= 0 && (info->data[info->cnt - i] == '-' || info->data[info->cnt - i] == '+'))
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	if (len_flag >= 0)
		return (-1);
	*flag_ref = flag;
	return (0);
}

int		ft_verif_suxX(char **flag_ref, int len_flag, t_struct *info, int i)
{
	char	*flag;

	flag = *flag_ref;
	if (info->data[info->cnt - i] == '*')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	else
	{
		while (info->data[info->cnt - i] >= '0' && info->data[info->cnt - i] <= '9')
		{
			flag[len_flag--] = info->data[info->cnt - i];
			i++;
		}
	}
	if (info->data[info->cnt - i] == '.')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
		if (info->data[info->cnt - i] == '*')
		{
			flag[len_flag--] = info->data[info->cnt - i];
			i++;
		}
		else
		{
			while (info->data[info->cnt - i] >= '0' &&
			info->data[info->cnt - i] <= '9')
			{
				flag[len_flag--] = info->data[info->cnt - i];
				i++;
			}
		}
	}
	while (info->data[info->cnt - i] == '-')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	if (len_flag >= 0)
		return (-1);
	*flag_ref = flag;
	return (0);
}
