/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:54:59 by jfieux            #+#    #+#             */
/*   Updated: 2021/02/22 11:50:38 by jfieux           ###   ########.fr       */
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
	char		letter;
}				t_struct;

typedef struct	s_size
{
	int			nbs;
	int			nbz;
	int			biggest;
}				t_size;


int				ft_printf(const char *data, ...);
int				ft_strlen(char *str);
int				ft_parsing(t_struct *info, va_list param);
int				ft_init_text(t_struct *info);
char			*ft_strjoin(char *s1, char *s2);
int				str_len_flag(t_struct *info);
int				ft_isletter(char c);
char			*ft_init_flag(int len_flag, t_struct *info);
char			*ft_verif_cp(char *flag, int len_flag, t_struct *info);
char			*ft_verif_id(char *flag, int len_flag, t_struct *info, int i);
int				ft_verif_suxX(char **flag_ref, int len_flag, t_struct *info, int i);
char			*ft_init_arg(t_struct *info, va_list param);
int				ft_treat_char(char c, char **arg);
int				ft_treat_str(char *str, char **arg);
int				ft_treat_pointer(unsigned long long adress, char **arg);
int				ft_treat_int(long int nb, char **arg);
char			*ft_malres(long int num, char *res, int *i);
char			*ft_init_int(long int num, char *res, int i);
int				ft_treat_hexa(long int nb, char **arg, int maj);
char			*ft_init_int_hexa(long int num, char *res, int maj, int i);
char			*ft_malloc_tmp(t_size *size, t_struct *info, char *flag, char *arg);
int				ft_nb_space(char *flag, int *i, int s);
int				ft_atoi(char *str);
int				ft_nb_zero(char *flag, int i, int s);
int				ft_init_res(t_struct *info, char *flag, char *arg);
char			*ft_fillin_strmin(t_size *size, char *tmp, char *arg);
char			*ft_fillin_othermin(t_size *size, char *tmp, char *arg);
char			*ft_fillin_str(t_size *size, char *tmp, char *arg);
char			*ft_fillin_other(t_size *size, char *tmp, char *arg);
char			*ft_strjoin(char *s1, char *s2);


#endif
