/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:26:32 by max               #+#    #+#             */
/*   Updated: 2021/01/19 11:14:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *input, ...)
{
	const char	*str;
	va_list		argsap;
	int			result;

	result = 0;
	str = ft_strdup(input);
	va_start(argsap, input);
	result = ft_parse_str(str, argsap, result);
	va_end(argsap);
	free((char *)str);
	return (result);
}
