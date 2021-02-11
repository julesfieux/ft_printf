/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:16:58 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/11 10:46:56 by jfieux           ###   ########.fr       */
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
	while (ft_isletter(info->data[info->cnt]) != 1) //tant que info->data n'est pas une letter
	{
		if (info->data[info->cnt] == '-')
			info->minus = 1;
		if (info->data[info->cnt] == '+')
			info->plus = 1;
		info->cnt++;
		len_flag++;
	}
	info->letter = info->data[info->cnt];
	return (len_flag);
}

char	*ft_malres(long int num, char *res, int *i)
{
	if (num == 0)
		(*i)++;
	if (num < 0)
	{
		(*i)++;
		num = -num;
	}
	while (num > 0)
	{
		(*i)++;
		num = num / 10;
	}
	if (!(res = malloc(sizeof(char) * ((*i) + 1))))
		return (0);
	res[*i] = '\0';
	(*i)--;
	return (res);
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
