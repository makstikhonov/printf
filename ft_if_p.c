/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:15:17 by max               #+#    #+#             */
/*   Updated: 2021/01/19 10:16:44 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_p_minus(t_flags flags, char *str, int len)
{
	int count;
	int i;

	count = 0;
	i = 0;
	count += ft_putstr("0x");
	count += ft_putstr(str);
	while (i < flags.width - len - 2)
	{
		count += ft_putchar(' ');
		i++;
	}
	return (count);
}

int	ft_if_p_nminus(t_flags flags, char *str, int len, unsigned long long p)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (p == 0 && flags.dot == 0)
		len = 0;
	flags.width = flags.width - 2;
	while (count < flags.width - len)
		count += ft_putchar(' ');
	count += ft_putstr("0x");
	if (!(p == 0 && flags.dot == 0))
		count += ft_putstr(str);
	return (count);
}

int	ft_if_p(unsigned long long p, t_flags flags)
{
	int		len;
	int		count;
	char	*str;

	str = NULL;
	if (!(str = ft_itoa_base(p, 16)))
		return (-1);
	len = ft_strlen(str);
	count = 0;
	if (flags.minus == 1)
		count += ft_if_p_minus(flags, str, len);
	else
		count += ft_if_p_nminus(flags, str, len, p);
	free(str);
	return (count);
}
