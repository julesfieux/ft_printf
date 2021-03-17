/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:37:38 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/17 17:54:42 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillin_strmin(t_struct *info, char *tmp)
{
	int		i;
	int		len_arg;

	i = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	len_arg = ft_strlen(info->arg);
	if (info->pnt == 1 && info->nbz < len_arg)
		len_arg = info->nbz;
	i = 0;
	while (i < len_arg)
	{
		tmp[i] = info->arg[i];
		i++;
	}
	return (tmp);
}

char	*ft_fillin_othermin1(t_struct *info, char *tmp, int *i, int *f)
{
	if (info->nbz > ft_strlen(info->arg))
		(*f) = (*i) - ft_strlen(info->arg);
	(*i) = 0;
	if (info->letter == 'c' && !info->arg[0])
	{
		info->co = (*f);
		tmp[(*f)++] = ' ';
	}
	else if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X')
	&& info->nbz == 0 && info->pnt == 1 && info->arg[0] == '0')
	{
		if (info->nbs == 0)
			tmp[(*f)] = 0;
		return (tmp);
	}
	else
	{
		if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
		info->arg[0] != '0' && info->nbz <= ft_strlen(info->arg))
			(*f) = (*f) + 2;
		while (info->arg[(*i)])
			tmp[(*f)++] = info->arg[(*i)++];
	}
	return (tmp);
}

char	*ft_fillin_othermin(t_struct *info, char *tmp)
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
	info->arg[0] != '0')
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
	tmp = ft_fillin_othermin1(info, tmp, &i, &f);
	return (tmp);
}

char	*ft_fillin_str(t_struct *info, char *tmp, int i)
{
	int		f;

	tmp[info->biggest] = '\0';
	if (info->zero == 1)
		while (i < info->biggest)
			tmp[i++] = '0';
	else
		while (i < info->biggest)
			tmp[i++] = ' ';
	f = i - ft_strlen(info->arg);
	if (info->pnt == 1 && info->nbz < ft_strlen(info->arg))
	{
		f = i - info->nbz;
		i = 0;
		while (i < info->nbz)
			tmp[f++] = info->arg[i++];
	}
	else
	{
		i = 0;
		while (info->arg[i])
			tmp[f++] = info->arg[i++];
	}
	return (tmp);
}

char	*ft_fillin_other1(t_struct *info, char *tmp, int *i)
{
	tmp[info->biggest] = '\0';
	if (info->letter == 'p' && info->nbs <= info->nbz &&
	info->nbs <= ft_strlen(info->arg))
	{
		while ((*i) < 2)
		{
			tmp[(*i)] = info->arg[(*i)];
			(*i)++;
		}
	}
	if ((info->letter == 'x' || info->letter == 'X') && info->sharp == 1 &&
	info->arg[0] != '0')
	{
		tmp[(*i)++] = '0';
		if (info->letter == 'x')
			tmp[(*i)++] = 'x';
		if (info->letter == 'X')
			tmp[(*i)++] = 'X';
	}
	while ((*i) < info->biggest)
		tmp[(*i)++] = ' ';
	(*i)--;
	return (tmp);
}

char	*ft_fillin_other2(t_struct *info, char *tmp, int *i, int *f)
{
	while (info->nbz > 0)
	{
		tmp[(*i)--] = '0';
		info->nbz--;
	}
	if ((*i) < 0)
		(*i) = 0;
	while (tmp[(*i)] != '\0')
		(*i)++;
	(*f) = (*i) - ft_strlen(info->arg);
	(*i) = 0;
	return (tmp);
}

char	*ft_fillin_other3(t_struct *info, char *tmp, int tmp_nbz, int *f)
{
	int i;

	i = 0;
	if (info->letter == 'p' && tmp_nbz == 0 && info->pnt == 1 &&
	info->arg[0] == '0')
	{
		(*f)++;
		while ((*f) < info->biggest)
			tmp[(*f)++] = info->arg[i++];
	}
	else
	{
		if (info->letter == 'p' && info->nbs <= tmp_nbz &&
		info->nbs <= ft_strlen(info->arg))
		{
			(*f) = (*f) + 2;
			i = i + 2;
		}
		while (info->arg[i])
			tmp[(*f)++] = info->arg[i++];
	}
	return (tmp);
}

char	*ft_fillin_other(t_struct *info, char *tmp)
{
	int		i;
	int		f;
	int		tmp_nbz;

	i = 0;
	tmp_nbz = info->nbz;
	tmp = ft_fillin_other1(info, tmp, &i);
	tmp = ft_fillin_other2(info, tmp, &i, &f);
	if (info->letter == 'c' && !info->arg[0])
		info->co = f - 1;
	else if ((info->letter == 'u' || info->letter == 'x' || info->letter == 'X')
	&& tmp_nbz == 0 && info->pnt == 1 && info->arg[0] == '0')
	{
		if (info->nbs == 0)
			tmp[f] = 0;
		return (tmp);
	}
	else
		tmp = ft_fillin_other3(info, tmp, tmp_nbz, &f);
	return (tmp);
}

char	*ft_fillin_intmin1(t_struct *info, char *tmp, int *f)
{
	int i;

	i = 0;
	tmp[info->biggest] = '\0';
	while (i < info->biggest)
		tmp[i++] = ' ';
	i = 0;
	if (info->arg[0] == '-')
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
	if (info->nbz > ft_strlen(info->arg))
		(*f) = i - ft_strlen(info->arg);
	return (tmp);
}

char	*ft_fillin_intmin(t_struct *info, char *tmp)
{
	int		i;
	int		f;

	tmp = ft_fillin_intmin1(info, tmp, &f);
	i = 0;
	f = 0;
	if (info->arg[0] == '-')
	{
		f++;
		i++;
	}
	else if (info->plus == 1)
		f++;
	else if (info->space == 1)
		f++;
	if (info->space == 1 && info->nbz == 0 && info->arg[0] == '0'
	&& info->pnt == 1)
		return (tmp);
	if (info->arg[0] == '0' && info->pnt == 1 && info->space == 0)
		return (tmp);
	while (info->arg[i])
		tmp[f++] = info->arg[i++];
	return (tmp);
}

char	*ft_fillin_int1(t_struct *info, char *tmp, int *i)
{
	int f;

	tmp[info->biggest] = '\0';
	while ((*i) < info->biggest)
		tmp[(*i)++] = ' ';
	(*i)--;
	f = info->nbz;
	while (f > 0)
	{
		tmp[(*i)--] = '0';
		f--;
	}
	if ((*i) < 0)
		(*i) = 0;
	if (info->arg[0] == '-')
	{
		if (ft_strlen(info->arg) > info->nbz)
		{
			while (tmp[(*i)])
				(*i)++;
			(*i) = (*i) - ft_strlen(info->arg);
		}
		tmp[(*i)] = '-';
	}
	return (tmp);
}

char	*ft_fillin_int2(t_struct *info, char *tmp, int *i)
{
	if (info->plus == 1 && info->arg[0] != '-')
	{
		if (ft_strlen(info->arg) > info->nbz)
		{
			while (tmp[(*i)])
				(*i)++;
			(*i) = (*i) - (ft_strlen(info->arg) + 1);
		}
		if (info->arg[0] == '0' && info->pnt == 1 && info->nbs == 0 &&
		info->nbz == 0)
			(*i)++;
		tmp[(*i)] = '+';
	}
	return (tmp);
}

char	*ft_fillin_int3(t_struct *info, char *tmp, int *i, int *f)
{
	if (info->space == 1 && info->plus != 1 && info->arg[0] != '-')
	{
		if (ft_strlen(info->arg) > info->nbz)
		{
			while (tmp[(*i)])
				(*i)++;
			(*i) = (*i) - (ft_strlen(info->arg) + 1);
		}
		if (info->arg[0] == '0' && info->pnt == 1 && info->nbs == 0 &&
		info->nbz == 0)
			(*i)++;
		tmp[(*i)] = ' ';
	}
	while (tmp[(*i)])
		(*i)++;
	(*f) = (*i) - ft_strlen(info->arg);
	(*i) = 0;
	if (info->arg[0] == '-')
	{
		(*f)++;
		(*i)++;
	}
	return (tmp);
}

char	*ft_fillin_int(t_struct *info, char *tmp)
{
	int		i;
	int		f;

	i = 0;
	tmp = ft_fillin_int1(info, tmp, &i);
	tmp = ft_fillin_int2(info, tmp, &i);
	tmp = ft_fillin_int3(info, tmp, &i, &f);
	if (info->space == 1 && info->nbz == 0 && info->arg[0] == '0' &&
	info->pnt == 1)
		return (tmp);
	if (info->arg[0] == '0' && info->pnt == 1 && info->space == 0)
		return (tmp);
	while (info->arg[i])
		tmp[f++] = info->arg[i++];
	return (tmp);
}
