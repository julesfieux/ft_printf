/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:03:14 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/19 10:06:47 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_init_int1(long long int num, char *res, int i)
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

char	*ft_init_int(long long int num, char *res, int i)
{
	long long	lim;
	const char	*limit = "-9223372036854775808";

	lim = -9223372036854775807;
	if (num == (lim - 1))
	{
		i = 0;
		while (limit[i])
		{
			res[i] = limit[i];
			i++;
		}
	}
	else
		res = ft_init_int1(num, res, i);
	return (res);
}

char	*ft_init_uint(unsigned long long int num, char *res, int i)
{
	while (num > 0)
	{
		res[i] = ((num % 10) + '0');
		i--;
		num = num / 10;
	}
	return (res);
}

char	*ft_init_int_hexa(unsigned long long int num, char *res, int maj, int i)
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
