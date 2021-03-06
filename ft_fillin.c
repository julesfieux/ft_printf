/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:37:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/11 11:13:19 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillin_strmin(t_struct *info, char *tmp, char *arg)
{
	int		i;
	int		len_arg;

	i = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	len_arg = ft_strlen(arg);
	if (info->pnt == 1 && info->nbz < len_arg)
		len_arg = info->nbz;
	i = 0;
	while (i < len_arg)
	{
		tmp[i] = arg[i];
		i++;
	}
	return (tmp);
}

char	*ft_fillin_othermin(t_struct *info, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	i = 0;
	if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
	arg[0] != '0')
	{
		tmp[i++] = '0';
		if (info->letter == 'x')
			tmp[i++] = 'x';
		if (info->letter == 'X')
			tmp[i++] = 'X';
		while (i < (info->nbz + 2))
			tmp[i++] = '0';
	}
	else
		while (i < info->nbz)
			tmp[i++] = '0';
	if (info->nbz > ft_strlen(arg))
		f = i - ft_strlen(arg);
	i = 0;
	if (info->letter == 'c' && !arg[0])
	{
		info->co = f;
		tmp[f++] = ' ';
	}
	else if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X')
	&& info->nbz == 0 && info->pnt == 1 && arg[0] == '0')
	{
		if (info->nbs == 0)
			tmp[f] = 0;
		return (tmp);
	}
	else
	{
		if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
		arg[0] != '0' && info->nbz <= ft_strlen(arg))
			f = f + 2;
		while (arg[i])
			tmp[f++] = arg[i++];
	}
	return (tmp);
}

char	*ft_fillin_str(t_struct *info, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	f = i - ft_strlen(arg);
	if (info->pnt == 1 && info->nbz < ft_strlen(arg))
	{
		f = i - info->nbz;
		i = 0;
		while (i < info->nbz)
			tmp[f++] = arg[i++];
	}
	else
	{
		i = 0;
		while (arg[i])
			tmp[f++] = arg[i++];
	}
	return (tmp);
}

char	*ft_fillin_other(t_struct *info, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	tmp[info->biggest] = '\0';
	if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
	arg[0] != '0')
	{
		tmp[i++] = '0';
		if (info->letter == 'x')
			tmp[i++] = 'x';
		if (info->letter == 'X')
			tmp[i++] = 'X';
	}
	while (i < info->biggest)
		tmp[i++] = ' ';
	i--;
	while (info->nbz > 0)
	{
		tmp[i--] = '0';
		info->nbz--;
	}
	if (i < 0)
		i = 0;
	while (tmp[i] != '\0')
		i++;
	f = i - ft_strlen(arg);
	i = 0;
	if (info->letter == 'c' && !arg[0])
		info->co = f - 1;
	else if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X')
	&& info->nbz == 0 && info->pnt == 1 && arg[0] == '0')
	{
		if (info->nbs == 0)
			tmp[f] = 0;
		return (tmp);
	}
	else
		while (arg[i])
			tmp[f++] = arg[i++];
	return (tmp);
}

char	*ft_fillin_intmin(t_struct *info, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	i = 0;
	if (arg[0] == '-')
	{
		tmp[i++] = '-';
		info->nbz++;
	}
	else if (info->plus == 1)
	{
		tmp[i++] = '+';
		info->nbz++;
	}
	else if (info->space == 1)
		i++;
	while (i < info->nbz)
		tmp[i++] = '0';
	if (info->nbz > ft_strlen(arg))
		f = i - ft_strlen(arg);
	i = 0;
	if (arg[0] == '-')
	{
		f++;
		i++;
	}
	else if (info->plus == 1)
		f++;
	else if (info->space == 1)
		f++;
	if (info->space == 1 && info->nbz == 0 && arg[0] == '0' && info->pnt == 1)
		return (tmp);
	if (arg[0] == '0' && info->pnt == 1 && info->space == 0)
		return (tmp);
	while (arg[i])
		tmp[f++] = arg[i++];
	return (tmp);
}

char	*ft_fillin_int(t_struct *info, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	i--;
	f = info->nbz;
	while (f > 0)
	{
		tmp[i--] = '0';
		f--;
	}
	if (i < 0)
		i = 0;
	if (arg[0] == '-')
	{
		if (ft_strlen(arg) > info->nbz)
		{
			while (tmp[i])
				i++;
			i = i - ft_strlen(arg);
		}
		tmp[i] = '-';
	}
	else if (info->plus == 1)
	{
		if (ft_strlen(arg) > info->nbz)
		{
			while (tmp[i])
				i++;
			i = i - (ft_strlen(arg) + 1);
		}
		if (arg[0] == '0' && info->pnt == 1 && info->nbs == 0 && info->nbz == 0)
			i++;
		tmp[i] = '+';
	}
	else if (info->space == 1)
	{
		if (ft_strlen(arg) > info->nbz)
		{
			while (tmp[i])
				i++;
			i = i - (ft_strlen(arg) + 1);
		}
		if (arg[0] == '0' && info->pnt == 1 && info->nbs == 0 && info->nbz == 0)
			i++;
		tmp[i] = ' ';
	}
	while (tmp[i])
		i++;
	f = i - ft_strlen(arg);
	i = 0;
	if (arg[0] == '-')
	{
		f++;
		i++;
	}
	if (info->space == 1 && info->nbz == 0 && arg[0] == '0' && info->pnt == 1)
		return (tmp);
	if (arg[0] == '0' && info->pnt == 1 && info->space == 0)
		return (tmp);
	while (arg[i])
		tmp[f++] = arg[i++];
	return (tmp);
}
