/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:06:35 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/24 11:42:39 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nb_space1(char *flag, t_struct *info, int nb, int s)
{
	char	*temp;

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
	return (nb);
}

int		ft_nb_space(char *flag, t_struct *info, int s, va_list param)
{
	int		nb;

	nb = 0;
	if (flag[info->i + s] == '*')
	{
		info->i++;
		nb = va_arg(param, int);
	}
	else
	{
		if ((nb = ft_nb_space1(flag, info, nb, s)) < 0)
			return (-1);
	}
	if (nb < 0)
	{
		nb = -nb;
		info->minus = 1;
	}
	return (nb);
}

int		ft_nb_zero1(char *flag, int s, int f, int i)
{
	char	*temp;

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

int		ft_nb_zero(char *flag, t_struct *info, int s, va_list param)
{
	int		f;
	int		i;

	f = 0;
	i = info->i;
	if (flag[i + s] == '*')
	{
		i = va_arg(param, int);
		if (i < 0)
			info->star_min = 1;
		if (i < 0 && info->letter != 's')
			i = 0;
	}
	else
	{
		if ((i = ft_nb_zero1(flag, s, f, i)) < 0)
			return (-1);
	}
	if (i < 0)
	{
		if (info->letter == 's')
			info->pnt = 0;
		i = -i;
	}
	return (i);
}

int		ft_nb_arg(t_struct *info, char *flag, va_list param)
{
	int s;

	s = 0;
	info->i = 0;
	info->nbz = 0;
	while (flag[s] == '-' || flag[s] == '+' || flag[s] == ' ')
		s++;
	if ((info->nbs = ft_nb_space(flag, info, s, param)) < 0)
		return (-1);
	if (flag[info->i + s] == '.')
	{
		info->i++;
		if ((info->nbz = ft_nb_zero(flag, info, s, param)) < 0)
			return (-1);
		info->i--;
	}
	if (!(info->arg = ft_init_arg(info, param)))
		return (-1);
	return (s);
}
