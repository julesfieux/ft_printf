/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:55:27 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/24 15:25:29 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsing(t_struct *info, va_list param)
{
	int		len_flag;
	char	*flag;

	while (info->data[info->cnt])
	{
		if (!(ft_init_text(info)))
			return (-1);
		if (info->data[info->cnt] == '%')
		{
			if ((len_flag = str_len_flag(info)) < 0)
				return (-1);
			if (!(flag = ft_init_flag(len_flag, info)))
				return (-1);
			if (!(ft_init_res(info, flag, param)))
				return (-1);
			free(flag);
			info->cnt++;
		}
	}
	return (0);
}

t_struct	*ft_init_struct(const char *data, int len)
{
	t_struct	*info;

	if (!(info = malloc(sizeof(t_struct))))
		return (NULL);
	if (!(info->data = malloc(sizeof(char) * (ft_strlen((char *)data) + 1))))
		return (NULL);
	while (data[len] != '\0')
	{
		info->data[len] = data[len];
		len++;
	}
	info->data[len] = '\0';
	if (!(info->res = malloc(sizeof(char) * 1)))
		return (NULL);
	info->res[0] = '\0';
	info->cnt = 0;
	return (info);
}

int		ft_printf(const char *data, ...)
{
	va_list 	param;
	t_struct	*info;
	int			len;

	if ((info = ft_init_struct(data, 0)) == NULL)
		return (-1);
	va_start(param, data);
	if (ft_parsing(info, param) < 0)
	{
		va_end(param);
		free(info->data);
		free(info->res);
		free(info);
		return (-1);
	}
	va_end(param);
	len = ft_strlen(info->res);
	write(1, info->res, len);
	free(info->data);
	free(info->res);
	free(info);
	return (len);
}
