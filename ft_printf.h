/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:05:47 by max               #+#    #+#             */
/*   Updated: 2021/01/19 11:14:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int					ft_printf(const char *str, ...);
int					ft_parse_str(const char *str, va_list argsap, int result);
t_flags				ft_flag_width(va_list argsap, t_flags flags,
					const char *str, int i);
t_flags				ft_flags_init(void);
int					ft_flag_dot(const char *str, int i, t_flags *flags,
					va_list argsap);
int					ft_flag_parse(const char *str, int i,
					t_flags *flags, va_list argsap);
int					ft_type(int c, t_flags flags, va_list argsap, int *result);
int					ft_if_c(char c, t_flags flags);
int					ft_if_s(char *str, t_flags flags);
int					ft_if_s_main(t_flags flags, int len, char *str);
int					ft_if_p(unsigned long long p, t_flags flags);
int					ft_if_p_minus(t_flags flags, char *str, int len);
int					ft_if_p_nminus(t_flags flags, char *str, int len,
					unsigned long long p);
int					ft_if_i(int integer, t_flags flags);
int					ft_if_i_if(t_flags flags, int len);
int					ft_if_i_nmin_ndot(t_flags flags, char *str,
					int integer, int minus);
int					ft_if_i_nmin_dot(t_flags flags, char *str,
					int integer, int minus);
int					ft_if_i_min_ndot(t_flags flags, char *str,
					int integer, int minus);
int					ft_if_i_min_dot(t_flags flags, char *str,
					int integer, int minus);
int					ft_if_u(unsigned int integer, t_flags flags);
int					ft_if_u_min_dot(t_flags flags, char *str, int len);
int					ft_if_u_min_ndot(t_flags flags, char *str, int len);
int					ft_if_u_nmin_dot(t_flags flags, char *str, int len);
int					ft_if_u_nmin_ndot(t_flags flags, char *str, int len);
int					ft_if_percent(t_flags flags);
int					ft_if_x(unsigned int integer, char c, t_flags flags);
char				*ft_if_x_lower(char *str);
int					ft_if_x_min_dot(t_flags flags, char *str, int len);
int					ft_if_x_min_ndot(t_flags flags, char *str, int len);
int					ft_if_x_nmin_dot(t_flags flags, char *str, int len);
int					ft_if_x_nmin_ndot(t_flags flags, char *str, int len);
int					ft_if_x(unsigned int integer, char c, t_flags flags);
int					ft_putstr(char *str);
int					ft_putchar(int c);
char				*ft_itoa_base (unsigned long nbr, int base);

#endif
