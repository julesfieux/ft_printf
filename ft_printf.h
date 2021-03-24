/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:54:59 by jfieux            #+#    #+#             */
/*   Updated: 2021/03/24 11:44:23 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_struct
{
	char		*res;
	char		*data;
	int			cnt;
	int			plus;
	int			minus;
	int			space;
	int			sharp;
	int			l;
	char		letter;
	int			star_min;
	int			i;
	int			len;
	int			*z_co;
	int			co;
	int			zero;
	int			pnt;
	int			nbs;
	int			nbz;
	int			biggest;
	char		*arg;
}				t_struct;

int				ft_printf(const char *data, ...);
int				ft_strlen(char *str);
int				ft_parsing(t_struct *info, va_list param);
int				ft_init_text(t_struct *info);
char			*ft_strjoin(char *s1, char *s2, t_struct *info);
int				str_len_flag(t_struct *info);
int				ft_isletter(char c);
char			*ft_init_flag(int len_flag, t_struct *info);
int				ft_verif_c(char **flag_ref, int len_flag, t_struct *info);
int				ft_verif_id(char **flag_ref, int len_flag,
				t_struct *info, int i);
int				ft_verif_spuxx(char **flag_ref, int len_flag,
				t_struct *info, int i);
int				ft_init_res(t_struct *info, char *flag, va_list param);
int				ft_nb_arg(t_struct *info, char *flag, va_list param);
int				ft_atoi(char *str);
char			*ft_init_arg(t_struct *info, va_list param);
int				ft_treat_cspdi(t_struct *info, int i, va_list param);
int				ft_treat_pointer(unsigned long long adress, t_struct *info);
int				ft_treat_int(long long int nb, t_struct *info);
char			*ft_malres(long long int num, char *res, int *i);
char			*ft_init_int(long long int num, char *res, int i);
int				ft_treat_uint(unsigned long long int nb, t_struct *info);
char			*ft_umalres(unsigned long long int num, char *res, int *i);
char			*ft_init_uint(unsigned long long int num, char *res, int i);
int				ft_treat_xx(t_struct *info, int i, va_list param);
char			*ft_init_int_hexa(unsigned long long int num,
				char *res, int maj, int i);
int				ft_treat_char(char c, t_struct *info);
void			ft_nbz_equal_nbs(char *flag, t_struct *info, int s);
char			*ft_fillin_all(t_struct *info);
char			*ft_malloc_tmp(t_struct *info);
char			*ft_fillin_strmin(t_struct *info, char *tmp);
char			*ft_fillin_str(t_struct *info, char *tmp, int i);
char			*ft_fillin_int(t_struct *info, char *tmp);
char			*ft_fillin_other(t_struct *info, char *tmp);
int				ft_z_co(t_struct *info);
int				ft_is_z_co(int *z_co, int i);

#endif
