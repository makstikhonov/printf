/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:43:39 by max               #+#    #+#             */
/*   Updated: 2021/01/19 10:17:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_s_main(t_flags flags, int len, char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (flags.minus == 1)
	{
		while (count < len)
			count += ft_putchar(str[count]);
		while (count < flags.width)
			count += ft_putchar(' ');
	}
	else
	{
		while (count < flags.width - len)
			count += ft_putchar(' ');
		while (i < len)
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	return (count);
}

int	ft_if_s(char *str, t_flags flags)
{
	int len;

	if (!str)
		str = "(null)";
	if ((flags.dot >= 0) && ((size_t)flags.dot > ft_strlen(str)))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
		len = flags.dot;
	else
		len = ft_strlen(str);
	return (ft_if_s_main(flags, len, str));
}
