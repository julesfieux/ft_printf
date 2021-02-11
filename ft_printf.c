/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:55:27 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/11 13:16:07 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_free()
{
	
}*/

int		ft_parsing(t_struct *info, va_list param)
{
	int		len_flag;
	char	*flag;
	char	*arg;

	while (info->data[info->cnt])
	{
		if (!(ft_init_text(info))) //info->cnt = % ou \0 
			return (-1);
		if (info->data[info->cnt] == '%')
		{
			len_flag = str_len_flag(info);
			if (!(flag = ft_init_flag(len_flag, info)))
				return (-1);
			if (!(arg = ft_init_arg(info, param)))
				return (-1);
			if (!(ft_init_res(info, flag, arg)))
				return (-1);
			info->cnt++;
		}
	}
	return (0);
}

int		ft_printf(const char *data, ...)
{
	va_list 	param;
	t_struct	*info;
	int			len;

	if (!(info = malloc(sizeof(t_struct))))
		return (-1);
	if (!(info->data = malloc(sizeof(char) * (ft_strlen((char *)data) + 1))))
		return (-1);
	info->data = (char *)data;
	if (!(info->res = malloc(sizeof(char))))
		return (-1);
	info->res[0] = '\0';
	va_start(param, data);
	if (ft_parsing(info, param) < 0)
		return (-1);
	write(1, info->res, ft_strlen(info->res));
	va_end(param);
	len = ft_strlen(info->res);
	//ft_free(); A faire!!!
	return (len);
}