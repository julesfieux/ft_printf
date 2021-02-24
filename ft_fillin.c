/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:37:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/24 11:42:18 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillin_strmin(t_size *size, char *tmp, char *arg)
{
	int		i;
	int		len_arg;

	i = 0;
	tmp[size->biggest] = '\0';
	while (i < size->biggest)
		tmp[i++] = ' ';
	len_arg = ft_strlen(arg);
	if (size->pnt == 1 && size->nbz < len_arg)
		len_arg = size->nbz;
	i = 0;
	while (i < len_arg)
	{
		tmp[i] = arg[i];
		i++;
	}
	return (tmp);
}

char	*ft_fillin_othermin(t_size *size, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	tmp[size->biggest] = '\0';
	while (i < size->biggest)
		tmp[i++] = ' ';
	i = 0;
	while (i < size->nbz)
		tmp[i++] = '0';
	if (size->nbz > ft_strlen(arg))
		f = i - ft_strlen(arg);
	i = 0;
	while (arg[i])
		tmp[f++] = arg[i++];
	return (tmp);
}

char	*ft_fillin_str(t_size *size, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	tmp[size->biggest] = '\0';
	while (i < size->biggest)
		tmp[i++] = ' ';
	f = i - ft_strlen(arg);
	if (size->pnt == 1 && size->nbz < ft_strlen(arg))
	{
		f = i - size->nbz;
		i = 0;
		while (i < size->nbz)
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

char	*ft_fillin_other(t_size *size, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	tmp[size->biggest] = '\0';
	while (i < size->biggest)
		tmp[i++] = ' ';
	i--;
	while (size->nbz > 0)
	{
		tmp[i--] = '0';
		size->nbz--;
	}
	if (i < 0)
		i = 0;
	while (tmp[i] != '\0')
		i++;
	f = i - ft_strlen(arg);
	i = 0;
	while (arg[i])
		tmp[f++] = arg[i++];
	return (tmp);
}

char	*ft_fillin_intmin(t_size *size, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	tmp[size->biggest] = '\0';
	while (i < size->biggest)
		tmp[i++] = ' ';
	i = 0;
	if (arg[0] == '-')
	{
		tmp[i++] = '-';
		size->nbz++;
		while (i < size->nbz)
			tmp[i++] = '0';
	}
	else
		while (i < size->nbz)
			tmp[i++] = '0';
	if (size->nbz > ft_strlen(arg))
		f = i - ft_strlen(arg);
	i = 0;
	if (arg[i] == '-')
	{
		f++;
		i++;
	}
	while (arg[i])
		tmp[f++] = arg[i++];
	return (tmp);
}

char	*ft_fillin_int(t_size *size, char *tmp, char *arg)
{
	int		i;
	int		f;

	i = 0;
	tmp[size->biggest] = '\0';
	while (i < size->biggest)
		tmp[i++] = ' ';
	i--;
	while (size->nbz > 0)
	{
		tmp[i--] = '0';
		size->nbz--;
	}
	if (i < 0)
		i = 0;
	if (arg[0] == '-')
		tmp[i] = '-';
	while (tmp[i])
		i++;
	f = i - ft_strlen(arg);
	i = 0;
	if (arg[0] == '-')
	{
		f++;
		i++;
	}
	while (arg[i])
		tmp[f++] = arg[i++];
	return (tmp);
}
