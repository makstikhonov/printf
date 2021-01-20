/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_i_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:42:48 by max               #+#    #+#             */
/*   Updated: 2021/01/19 10:16:05 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_i_if(t_flags flags, int len)
{
	int count;
	int t;
	int i;

	count = 0;
	i = 0;
	t = 0;
	if (flags.width > flags.dot && flags.width > len)
	{
		t = flags.width - len;
		if (flags.dot > len)
			t = flags.width - flags.dot;
		while (i < t)
		{
			count += ft_putchar(' ');
			i++;
		}
	}
	return (count);
}
