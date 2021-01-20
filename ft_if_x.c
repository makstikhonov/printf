/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:32:02 by max               #+#    #+#             */
/*   Updated: 2021/01/19 10:20:26 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_x_min_dot(t_flags flags, char *str, int len)
{
	int i;
	int t;
	int count;

	i = 0;
	t = 0;
	count = 0;
	while (count < flags.dot - len)
		count += ft_putchar('0');
	while (i < len)
		count += ft_putchar(str[i++]);
	i = 0;
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

int	ft_if_x_min_ndot(t_flags flags, char *str, int len)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (count < len)
		count += ft_putchar(str[count]);
	while (i < flags.width - len)
	{
		count += ft_putchar(' ');
		i++;
	}
	return (count);
}

int	ft_if_x_nmin_dot(t_flags flags, char *str, int len)
{
	int i;
	int t;
	int count;

	i = 0;
	t = 0;
	count = 0;
	if (flags.width > flags.dot && flags.width > len)
	{
		t = flags.width - len;
		if (flags.dot > len)
			t = flags.width - flags.dot;
		while (count < t)
			count += ft_putchar(' ');
	}
	t = 0;
	while (i < flags.dot - len)
	{
		count += ft_putchar('0');
		i++;
	}
	while (t < len)
		count += ft_putchar(str[t++]);
	return (count);
}

int	ft_if_x_nmin_ndot(t_flags flags, char *str, int len)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (count < flags.width - len)
	{
		if (flags.zero == 1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	while (i < len)
		count += ft_putchar(str[i++]);
	return (count);
}

int	ft_if_x(unsigned int integer, char c, t_flags flags)
{
	char	*str;
	int		len;
	int		count;

	count = 0;
	if (!(str = ft_itoa_base(integer, 16)))
		return (-1);
	if (c == 'X')
		str = ft_if_x_lower(str);
	len = ft_strlen(str);
	if (integer == 0 && flags.dot >= 0)
		len = 0;
	if (flags.dot >= 0 && flags.minus == 1)
		count += ft_if_x_min_dot(flags, str, len);
	else if (flags.dot < 0 && flags.minus == 1)
		count += ft_if_x_min_ndot(flags, str, len);
	if (flags.dot >= 0 && flags.minus == 0)
		count += ft_if_x_nmin_dot(flags, str, len);
	else if (flags.dot < 0 && flags.minus == 0)
		count += ft_if_x_nmin_ndot(flags, str, len);
	free(str);
	return (count);
}
