/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:27:00 by max               #+#    #+#             */
/*   Updated: 2021/01/19 13:20:44 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_flags_init(void)
{
	t_flags		flags;

	flags.type = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	return (flags);
}

t_flags		ft_flag_width(va_list argsap, t_flags flags, const char *str, int i)
{
	if (str[i] == '*')
	{
		flags.star = 1;
		flags.width = va_arg(argsap, int);
		if (flags.width < 0)
		{
			flags.minus = 1;
			flags.width *= -1;
		}
	}
	else
	{
		if (flags.star == 1)
			flags.width = 0;
		flags.width = flags.width * 10 + (str[i] - '0');
	}
	return (flags);
}

int			ft_flag_dot(const char *str, int i,
			t_flags *flags, va_list argsap)
{
	i++;
	if (str[i] == '*')
	{
		flags->dot = va_arg(argsap, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
			flags->dot = flags->dot * 10 + (str[i++] - '0');
	}
	return (i);
}
