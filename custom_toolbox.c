/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:16:58 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/26 10:36:13 by jfieux           ###   ########.fr       */
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

int		ft_nb_space(char *flag, t_struct *info, int s, va_list param)
{
	char	*temp;
	int		nb;

	if (flag[info->i + s] == '*')
	{
		info->i++;
		nb = va_arg(param, int);
	}
	else
	{
		while (flag[info->i + s] >= '0' && flag[info->i + s] <= '9')
			info->i++;
		if (!(temp = malloc(sizeof(char) * (info->i + 1))))
			return (-1);
		info->i = 0;
		while (flag[info->i + s] >= '0' && flag[info->i + s] <= '9')
		{
			temp[info->i] = flag[info->i + s];
			info->i++;
		}
		temp[info->i] = '\0';
		nb = ft_atoi(temp);
		free(temp);
	}
	if (nb < 0)
	{
		nb = -nb;
		info->minus = 1;
	}
	return (nb);
}

int		ft_nb_zero(char *flag, t_struct *info, int s, va_list param)
{
	char	*temp;
	int		f;

	f = 0;
	if (flag[info->i + s] == '*')
		info->i = va_arg(param, int);
	else
	{
		while (flag[info->i + s] >= '0' && flag[s + info->i++] <= '9')
			f++;
		if (!f)
			return (0);
		if (!(temp = malloc(sizeof(char) * (f + 1))))
			return (-1);
		info->i = info->i - f;
		f = 0;
		while (flag[info->i + s] >= '0' && flag[info->i + s] <= '9')
			temp[f++] = flag[s + info->i++];
		temp[f] = '\0';
		info->i = ft_atoi(temp);
		free(temp);
	}
	if (info->i < 0)
	{
		info->i = -info->i;
		info->minus = 1;
	}
	return (info->i);
}
