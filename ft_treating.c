/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:39:00 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/12 11:55:29 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_char(char c, char **arg)
{
	char *tmp;

	if (!(tmp = malloc(sizeof(char) * 2)))
		return (0);
	tmp[0] = c;
	tmp[1] = '\0';
	*arg = tmp;
	return (1);
}

int		ft_treat_str(char *str, char **arg)
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
	}
	else
	{
		if (!(tmp = malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (0);
		while (str[i])
		{
			tmp[i] = str[i];
			i++;
		}
	}
	tmp[i] = '\0';
	*arg = tmp;
	return (1);
}

int		ft_treat_pointer(unsigned long long adress, char **arg)
{
	int					len;
	unsigned long long	temp;
	const char			base[16] = "0123456789abcdef";
	char				null[3] = "0x0";
	char				*tmp;

	temp = adress;
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
	*arg = tmp;
	return (1);
}

int		ft_treat_int(long long int nb, char **arg)
{
	int			i;

	i = 0;
	*arg = NULL;
	if (!(*arg = ft_malres(nb, *arg, &i)))
		return (0);
	if (nb == 0)
	{
		*arg[0] = '0';
		return (1);
	}
	*arg = ft_init_int(nb, *arg, i);
	return (1);
}

int		ft_treat_uint(unsigned long long int nb, char **arg)
{
	int			i;

	i = 0;
	*arg = NULL;
	if (!(*arg = ft_umalres(nb, *arg, &i)))
		return (0);
	if (nb == 0)
	{
		*arg[0] = '0';
		return (1);
	}
	*arg = ft_init_uint(nb, *arg, i);
	return (1);
}

int		ft_treat_hexa(unsigned long long int nb, char **arg, int maj)
{
	int			i;
	unsigned long long int	num;
	char		*tmp;

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
		*arg = tmp;
		return (1);
	}
	tmp = ft_init_int_hexa(nb, tmp, maj, i);
	*arg = tmp;
	return (1);
}
