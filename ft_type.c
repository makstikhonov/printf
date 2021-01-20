/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:27:56 by max               #+#    #+#             */
/*   Updated: 2021/01/19 11:14:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(int c, t_flags flags, va_list argsap, int *result)
{
	int res;

	res = 0;
	if (c == 'c')
		res = ft_if_c(va_arg(argsap, int), flags);
	else if (c == 's')
		res = ft_if_s(va_arg(argsap, char *), flags);
	else if (c == 'p')
		res = ft_if_p(va_arg(argsap, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		res = ft_if_i(va_arg(argsap, int), flags);
	else if (c == 'u')
		res = ft_if_u((unsigned int)va_arg(argsap, unsigned int), flags);
	else if (c == 'x' || c == 'X')
		res = ft_if_x(va_arg(argsap, unsigned int), c, flags);
	else if (c == '%')
		res = ft_if_percent(flags);
	*result += res;
	return (res);
}
