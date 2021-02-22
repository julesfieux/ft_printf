/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:16:58 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/22 11:58:54 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_len_flag(t_struct *info)
{
	int len_flag;

	len_flag = 0;
	info->plus = 0;
	info->minus = 0;
	info->cnt++;
	while (ft_isletter(info->data[info->cnt]) != 1 && info->data[info->cnt])
	{
		if (info->data[info->cnt] == '-')
			info->minus = 1;
		if (info->data[info->cnt] == '+')
			info->plus = 1;
		info->cnt++;
		len_flag++;
	}
	if (!info->data[info->cnt])
		return (-1);
	info->letter = info->data[info->cnt];
	return (len_flag);
}

char	*ft_init_int(long int num, char *res, int i)
{
	if (num < 0)
	{
		num = -num;
		res[0] = '-';
	}
	while (num > 0)
	{
		res[i] = ((num % 10) + '0');
		i--;
		num = num / 10;
	}
	return (res);
}

char	*ft_init_int_hexa(long int num, char *res, int maj, int i)
{
	const char basemin[] = "0123456789abcdef";
	const char basemaj[] = "0123456789ABCDEF";

	if (maj == 0)
	{
		while (num > 0)
		{
			res[i--] = basemin[num % 16];
			num = num / 16;
		}
	}
	else
	{
		while (num > 0)
		{
			res[i--] = basemaj[num % 16];
			num = num / 16;
		}
	}
	return (res);
}

int		ft_nb_space(char *flag, int *i, int s)
{
	char	*temp;
	int		nb;

	while (flag[(*i) + s] >= '0' && flag[(*i) + s] <= '9')
		(*i)++;
	if (!(temp = malloc(sizeof(char) * ((*i) + 1))))
		return (-1);
	*i = 0;
	while (flag[(*i) + s] >= '0' && flag[(*i) + s] <= '9')
	{
		temp[(*i)] = flag[(*i) + s];
		(*i)++;
	}
	temp[(*i)] = '\0';
	nb = ft_atoi(temp);
	free(temp);
	return (nb);
}

int		ft_nb_zero(char *flag, int i, int s)
{
	char	*temp;
	int		f;

	f = 0;
	while (flag[i + s] >= '0' && flag[s + i++] <= '9')
		f++;
	if (!f)
		return (0);
	if (!(temp = malloc(sizeof(char) * (f + 1))))
		return (-1);
	i = i - f;
	f = 0;
	while (flag[i + s] >= '0' && flag[i + s] <= '9')
		temp[f++] = flag[s + i++];
	temp[f] = '\0';
	i = ft_atoi(temp);
	free(temp);
	return (i);
}
