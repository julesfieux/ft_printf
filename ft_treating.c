/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:39:00 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/18 12:04:09 by jfieux           ###   ########.fr       */
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

char	*ft_treat_pointer1(unsigned long long adress, int len, char *tmp)
{
	unsigned long long	temp;
	const char			base[16] = "0123456789abcdef";

	temp = adress;
	if (adress != 0)
	{
		while (temp > 0)
		{
			temp = temp / 16;
			len++;
		}
		if (!(tmp = malloc(sizeof(char) * (len + 1))))
			return (0);
		tmp[0] = '0';
		tmp[1] = 'x';
		tmp[len--] = '\0';
		while (len > 2)
		{
			tmp[len--] = base[adress % 16];
			adress = adress / 16;
		}
		tmp[len] = base[adress];
	}
	return (tmp);
}

int		ft_treat_pointer(unsigned long long adress, t_struct *info)
{
	int					len;
	const char			null[3] = "0x0";
	char				*tmp;

	len = 2;
	if (adress == 0)
	{
		if (!(tmp = malloc(sizeof(char) * 6)))
			return (0);
		len = 0;
		while (len < 3)
		{
			tmp[len] = null[len];
			len++;
		}
		tmp[len] = '\0';
	}
	else
		tmp = NULL;
	tmp = ft_treat_pointer1(adress, len, tmp);
	info->arg = tmp;
	return (1);
}

int		ft_treat_int(long long int nb, t_struct *info)
{
	int			i;

	i = 0;
	info->arg = NULL;
	if (!(info->arg = ft_malres(nb, info->arg, &i)))
		return (0);
	if (nb == 0)
	{
		info->arg[0] = '0';
		return (1);
	}
	info->arg = ft_init_int(nb, info->arg, i);
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

int		ft_treat_hexa(unsigned long long int nb, t_struct *info, int maj)
{
	int						i;
	unsigned long long int	num;
	char					*tmp;

	i = 0;
	num = nb;
	if (num == 0)
		i++;
	while (num > 0)
	{
		i++;
		num = num / 16;
	}
	if (!(tmp = malloc(sizeof(char) * (i + 1))))
		return (0);
	tmp[i--] = '\0';
	if (nb == 0)
	{
		tmp[0] = '0';
		info->arg = tmp;
		return (1);
	}
	tmp = ft_init_int_hexa(nb, tmp, maj, i);
	info->arg = tmp;
	return (1);
}
