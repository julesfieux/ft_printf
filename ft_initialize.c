/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:07:04 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/19 16:28:00 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_init_text(t_struct *info)
{
	int		cnt;
	char	*tmp;
	int		i;

	if (info->data[info->cnt] != '\0' && info->data[info->cnt] != '%')
	{
		cnt = 0;
		while (info->data[info->cnt] != '\0' && info->data[info->cnt] != '%')
		{
			info->cnt++;
			cnt++;
		}
		info->cnt = info->cnt - cnt;
		if (!(tmp = malloc(sizeof(char) * (cnt + 1))))
			return (0);
		i = 0;
		while (i < cnt)
			tmp[i++] = info->data[info->cnt++];
		tmp[i] = '\0';
		if (!(info->res = ft_strjoin(info->res, tmp)))
		{
			free(tmp);
			return (0);
		}
	}
	return (1);
}

char	*ft_init_flag(int len_flag, t_struct *info)
{
	char	*flag;

	if (!(flag = malloc(sizeof(char) * (len_flag + 1))))
		return (NULL);
	flag[len_flag] = '\0';
	len_flag--;
	if (info->letter == 'c' || info->letter == 'p')
		if (!(flag = ft_verif_cp(flag, len_flag, info)))
		{
			free(flag);
			return (NULL);
		}
	if (info->letter == 'i' || info->letter == 'd' || info->letter == '%')
		if (!(flag = ft_verif_id(flag, len_flag, info, 1)))
		{
			free(flag);
			return (NULL);
		}
	if (info->letter == 'u' || info->letter == 'x' || info->letter == 'X')
		if (!(flag = ft_verif_uxX(flag, len_flag, info, 1)))
		{
			free(flag);
			return (NULL);
		}
	return (flag);
}

char	*ft_init_arg(t_struct *info, va_list param)
{
	//info->data[info->cnt] est sur la letter
	char	*arg;
	int		i;

	i = 0;
	if (info->letter == 'c')
		i = ft_treat_char(va_arg(param, int), &arg);
	if (info->letter == 's')
		i = ft_treat_str(va_arg(param, char *), &arg);
	if (info->letter == 'p')
		i = ft_treat_pointer(va_arg(param, unsigned long long), &arg);
	if (info->letter == 'd' || info->letter == 'i')
		i = ft_treat_int(va_arg(param, int), &arg);
	if (info->letter == 'u')
		i = ft_treat_int(va_arg(param, unsigned int), &arg);
	if (info->letter == 'x')
		i = ft_treat_hexa(va_arg(param, unsigned int), &arg, 0);
	if (info->letter == 'X')
		i = ft_treat_hexa(va_arg(param, unsigned int), &arg, 1);
	if (info->letter == '%')
		i = ft_treat_char('%', &arg);
	if (!i) //si il y a une erreur i=0 et on renvoie NULL
		return (NULL);
	return (arg);
}

int		ft_init_res(t_struct *info, char *flag, char *arg)
{
	t_size	*size;
	char	*tmp;

	if (!(size = malloc(sizeof(t_size))))
		return (0);
	if (!(tmp = ft_malloc_tmp(size, info, flag, arg)))
	{
		free(size);
		return (0);
	}
	if (info->minus == 1)
	{
		if (info->letter == 's')
			tmp = ft_fillin_strmin(size, tmp, arg);
		else
			tmp = ft_fillin_othermin(size, tmp, arg);
	}
	else
	{
		if (info->letter == 's')
			tmp = ft_fillin_str(size, tmp, arg);
		else
			tmp = ft_fillin_other(size, tmp, arg);
	}
	free(size);
	if (!(info->res = ft_strjoin(info->res, tmp)))
	{
		free(tmp);
		return (0);
	}
	return (1);
}
