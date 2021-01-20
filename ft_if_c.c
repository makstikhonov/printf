/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:28:15 by max               #+#    #+#             */
/*   Updated: 2021/01/17 17:29:27 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_if_c(char c, t_flags flags)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putchar(c);
		while (i < flags.width - 1)
		{
			count += ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (count < flags.width - 1)
			count += ft_putchar(' ');
		count += ft_putchar(c);
	}
	return (count);
}
