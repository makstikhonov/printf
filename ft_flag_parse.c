/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:26:43 by max               #+#    #+#             */
/*   Updated: 2021/01/19 11:14:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_parse(const char *str, int i, t_flags *flags, va_list argsap)
{
	while (str[i] != '\0' && ft_strchr(" cspdiuxX%-0123456789.*", str[i]))
	{
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, i, flags, argsap);
		if (str[i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		if (str[i] == '*' || ft_isdigit(str[i]))
			*flags = ft_flag_width(argsap, *flags, str, i);
		if (ft_strchr("cspdiuxX%", str[i]))
		{
			flags->type = str[i];
			return (i);
		}
		i++;
	}
	return (i);
}
