/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:46:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/12 12:08:08 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_verif_cp(char **flag_ref, int len_flag, t_struct *info)
{
	int i;
	char	*flag;

	flag = *flag_ref;
	i = 1;
	if (info->letter == 'c' && info->l > 2)
		return (-1);
	if (info->letter == 'p' && info->l > 0)
		return (-1);
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
		while (info->data[info->cnt - i] <= '9' &&
		info->data[info->cnt - i] >= '0')
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
	if ((info->letter == 'i' || info->letter == 'd') && info->l > 2)
		return (-1);
	if (info->letter == '%' && info->l > 0)
		return (-1);
	if (info->data[info->cnt - i] == '*')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	else
	{
		while (info->data[info->cnt - i] >= '0' &&
		info->data[info->cnt - i] <= '9' && len_flag >= 0)
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
			while (len_flag >= 0 && info->data[info->cnt - i] >= '0' &&
			info->data[info->cnt - i] <= '9')
			{
				flag[len_flag--] = info->data[info->cnt - i];
				i++;
			}
		}
	}
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

int		ft_verif_suxX(char **flag_ref, int len_flag, t_struct *info, int i)
{
	char	*flag;

	flag = *flag_ref;
	if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X' ||
	info->letter == 's') && info->l > 2)
		return (-1);
	if (info->data[info->cnt - i] == '*')
	{
		flag[len_flag--] = info->data[info->cnt - i];
		i++;
	}
	else
	{
		while (len_flag >= 0 && info->data[info->cnt - i] >= '0' &&
		info->data[info->cnt - i] <= '9')
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
			while (len_flag >= 0 && info->data[info->cnt - i] >= '0' &&
			info->data[info->cnt - i] <= '9')
			{
				flag[len_flag--] = info->data[info->cnt - i];
				i++;
			}
		}
	}
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
