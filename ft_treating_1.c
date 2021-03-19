/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:39:00 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/19 10:49:37 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_char(char c, t_struct *info)
{
	char *tmp;

	if (!(tmp = malloc(sizeof(char) * 2)))
		return (0);
	tmp[0] = c;
	tmp[1] = '\0';
	info->arg = tmp;
	return (1);
}

char	*ft_treat_str1(char *str, int i, char *tmp)
{
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		ft_treat_str(char *str, t_struct *info)
{
	int			i;
	char		*tmp;
	const char	null[6] = "(null)";

	i = 0;
	if (str == NULL)
	{
		if (!(tmp = malloc(sizeof(char) * 7)))
			return (0);
		while (null[i])
		{
			tmp[i] = null[i];
			i++;
		}
		tmp[i] = '\0';
	}
	else
	{
		if (!(tmp = malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (0);
		tmp = ft_treat_str1(str, i, tmp);
	}
	info->arg = tmp;
	return (1);
}

int		ft_treat_uint(unsigned long long int nb, t_struct *info)
{
	int			i;

	i = 0;
	info->arg = NULL;
	if (!(info->arg = ft_umalres(nb, info->arg, &i)))
		return (0);
	if (nb == 0)
	{
		info->arg[0] = '0';
		return (1);
	}
	info->arg = ft_init_uint(nb, info->arg, i);
	return (1);
}

int		ft_treat_cspdi(t_struct *info, int i, va_list param)
{
	if (info->letter == 'c')
	{
		if (info->l == 1)
			i = ft_treat_char(va_arg(param, long int), info);
		else if (info->l == 2)
			i = ft_treat_char(va_arg(param, long long int), info);
		else
			i = ft_treat_char(va_arg(param, int), info);
	}
	if (info->letter == 's')
		i = ft_treat_str(va_arg(param, char *), info);
	if (info->letter == 'p')
		i = ft_treat_pointer(va_arg(param, unsigned long long), info);
	if (info->letter == 'd' || info->letter == 'i')
	{
		if (info->l == 1)
			i = ft_treat_int(va_arg(param, long int), info);
		else if (info->l == 2)
			i = ft_treat_int(va_arg(param, long long int), info);
		else
			i = ft_treat_int(va_arg(param, int), info);
	}
	return (i);
}
