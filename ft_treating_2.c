/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:47:26 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/19 11:11:40 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_treat_xx(t_struct *info, int i, va_list param)
{
	if (info->letter == 'x')
	{
		if (info->l == 1)
			i = ft_treat_hexa(va_arg(param, unsigned long int), info, 0);
		else if (info->l == 2)
			i = ft_treat_hexa(va_arg(param, unsigned long long int), info, 0);
		else
			i = ft_treat_hexa(va_arg(param, unsigned int), info, 0);
	}
	if (info->letter == 'X')
	{
		if (info->l == 1)
			i = ft_treat_hexa(va_arg(param, unsigned long int), info, 1);
		else if (info->l == 2)
			i = ft_treat_hexa(va_arg(param, unsigned long long int), info, 1);
		else
			i = ft_treat_hexa(va_arg(param, unsigned int), info, 1);
	}
	return (i);
}
