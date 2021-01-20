/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:27:38 by max               #+#    #+#             */
/*   Updated: 2021/01/19 11:14:18 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parse_str(const char *str, va_list argsap, int result)
{
	int			i;
	t_flags		flags;

	i = 0;
	while (str[i] != '\0')
	{
		flags = ft_flags_init();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (str[i++] == ' ')
				result += ft_putchar(' ');
			i = ft_flag_parse(str, i, &flags, argsap);
			if (ft_strchr("cspdiuxX%", str[i]))
			{
				if (ft_type((char)flags.type, flags, argsap, &result) < 0)
					return (-1);
			}
			else if (str[i])
				result += ft_putchar(str[i]);
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	return (result);
}
