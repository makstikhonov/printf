/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:13:55 by max               #+#    #+#             */
/*   Updated: 2021/01/19 10:16:52 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_percent(t_flags flags)
{
	int		i;
	char	c;
	int		count;

	i = 0;
	c = ' ';
	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putchar('%');
		while (i < flags.width - 1)
		{
			count += ft_putchar(' ');
			i++;
		}
	}
	else
	{
		if (flags.zero)
			c = '0';
		while (count < flags.width - 1)
			count += ft_putchar(c);
		count += ft_putchar('%');
	}
	return (count);
}
