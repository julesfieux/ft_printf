/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:57:17 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/24 18:18:47 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_z_co(int *z_co, int i)
{
	int f;

	f = 0;
	while (z_co[f] >= 0)
	{
		if (i == z_co[f])
			return (1);
		f++;
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (sign == 1 && res > 922337203685477580)
			return (-1);
		else if (res > 922337203685477580)
			return (0);
	}
	return (res * sign);
}

char	*ft_strjoin(char *s1, char *s2, t_struct *info)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	info->len = info->len + ft_strlen(s2);
	if (s2[0] == '\0' && info->letter == 'c')
		info->len++;
	free(s2);
	free(s1);
	return (res);
}

int		ft_isletter(char c)
{
	const char	letter[10] = "cspdiuxX\%";
	int			i;

	i = 0;
	while (letter[i] != '\0')
	{
		if (letter[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_nbz_equal_nbs(char *flag, t_struct *info, int s)
{
	if (flag[info->i + s] != '.')
	{
		if (info->zero == 1 && info->minus == 0 && (info->letter == 'd' ||
		info->letter == 'i' || info->letter == 'u' || info->letter == 'x' ||
		info->letter == 'X' || info->letter == '%'))
		{
			if (info->sharp == 0)
				info->nbz = info->nbs;
			else
			{
				if (info->arg[0] == '0' || info->nbz == 0)
					info->nbz = info->nbs;
			}
		}
	}
	else
	{
		if (info->nbz == 0 && info->zero == 1 && info->minus == 0 &&
		info->star_min == 1)
		{
			info->nbz = info->nbs;
			if (info->arg[0] == '-')
				info->nbz--;
		}
	}
}
