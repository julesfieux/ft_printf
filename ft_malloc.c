/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:52:21 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/19 10:43:27 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_malres(long long int num, char *res, int *i)
{
	long long lim;

	lim = -9223372036854775807;
	if (num == 0)
		(*i)++;
	if (num == (lim - 1))
		*i = 20;
	else
	{
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
	}
	if (!(res = malloc(sizeof(char) * ((*i) + 1))))
		return (0);
	res[*i] = '\0';
	(*i)--;
	return (res);
}

char	*ft_umalres(unsigned long long int num, char *res, int *i)
{
	if (num == 0)
		(*i)++;
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
