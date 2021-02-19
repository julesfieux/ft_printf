/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:46:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/19 14:26:32 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_verif_cp(char *flag, int len_flag, t_struct *info)
{
	int i;

	i = 1;
	while (info->data[info->cnt - i] == '-')
	{
		flag[len_flag] = info->data[info->cnt - i];
		len_flag--;
		i++;
	}
	while (len_flag >= 0)
	{
		if (info->data[info->cnt - i] > '9' && info->data[info->cnt - i] < '0')
			return (NULL);
		flag[len_flag] = info->data[info->cnt - i];
		len_flag--;
		i++;
	}
	return (flag);
}

char	*ft_verif_id(char *flag, int len_flag, t_struct *info, int i)
{
	while (len_flag >= 0 && (info->data[info->cnt - i] == '-' || info->data[info->cnt - i] == '+'))
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	while (len_flag >= 0 && (info->data[info->cnt - i] < '0' || info->data[info->cnt - i] > '9'))
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	if (info->data[info->cnt - i] == '.')
	{
		len_flag--;
		i++;
		while (info->data[info->cnt - i] < '0' ||
		info->data[info->cnt - i] > '9')
		{
			flag[len_flag--] = info->data[info->cnt - i];
			i++;
		}
	}
	if (len_flag >= 0)
		return (NULL);
	return (flag);
}

char	*ft_verif_uxX(char *flag, int len_flag, t_struct *info, int i)
{
	while (info->data[info->cnt - i] == '-')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	while (info->data[info->cnt - i] < '0' || info->data[info->cnt - i] > '9')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	if (info->data[info->cnt - i] == '.')
	{
		len_flag--;
		i++;
		while (info->data[info->cnt - i] < '0' ||
		info->data[info->cnt - i] > '9')
		{
			flag[len_flag--] = info->data[info->cnt - i];
			i++;
		}
	}
	if (len_flag >= 0)
		return (NULL);
	return (flag);
}
