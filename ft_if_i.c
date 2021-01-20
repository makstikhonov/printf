/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:32:02 by max               #+#    #+#             */
/*   Updated: 2021/01/19 10:16:27 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_i_min_dot(t_flags flags, char *str, int integer, int minus)
{
	int i;
	int count;
	int len;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	if (integer == 0 && flags.dot >= 0)
		len = 0;
	if (minus == 1)
		count += ft_putchar('-');
	while (i < flags.dot - len)
	{
		count += ft_putchar('0');
		i++;
	}
	i = 0;
	while (i < len)
		count += ft_putchar(str[i++]);
	count += ft_if_i_if(flags, len);
	return (count);
}

int	ft_if_i_min_ndot(t_flags flags, char *str, int integer, int minus)
{
	int count;
	int i;
	int len;

	count = 0;
	i = 0;
	len = ft_strlen(str);
	if (integer == 0 && flags.dot >= 0)
		len = 0;
	if (minus == 1)
		count += ft_putchar('-');
	while (i < len)
		count += ft_putchar(str[i++]);
	i = 0;
	while (i < flags.width - len)
	{
		count += ft_putchar(' ');
		i++;
	}
	return (count);
}

int	ft_if_i_nmin_dot(t_flags flags, char *str, int integer, int minus)
{
	int i;
	int count;
	int len;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	if (integer == 0 && flags.dot >= 0)
		len = 0;
	count += ft_if_i_if(flags, len);
	if (minus == 1)
		count += ft_putchar('-');
	while (i < flags.dot - len)
	{
		count += ft_putchar('0');
		i++;
	}
	i = 0;
	while (i < len)
		count += ft_putchar(str[i++]);
	return (count);
}

int	ft_if_i_nmin_ndot(t_flags flags, char *str, int integer, int minus)
{
	int count;
	int i;
	int len;

	count = 0;
	i = 0;
	len = ft_strlen(str);
	if (integer == 0 && flags.dot >= 0)
		len = 0;
	if (minus == 1 && flags.zero == 1)
		count += ft_putchar('-');
	while (i < flags.width - len)
	{
		if (flags.zero == 1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		i++;
	}
	if (minus == 1 && flags.zero == 0)
		count += ft_putchar('-');
	i = 0;
	while (i < len)
		count += ft_putchar(str[i++]);
	return (count);
}

int	ft_if_i(int integer, t_flags flags)
{
	char	*str;
	int		count;
	int		minus;

	minus = 0;
	if (integer < 0)
	{
		minus = 1;
		integer *= -1;
		flags.width--;
	}
	count = 0;
	if (!(str = ft_itoa(integer)))
		return (-1);
	if (flags.dot >= 0 && flags.minus == 1)
		count += ft_if_i_min_dot(flags, str, integer, minus);
	else if (flags.dot < 0 && flags.minus == 1)
		count += ft_if_i_min_ndot(flags, str, integer, minus);
	if (flags.dot >= 0 && flags.minus == 0)
		count += ft_if_i_nmin_dot(flags, str, integer, minus);
	else if (flags.dot < 0 && flags.minus == 0)
		count += ft_if_i_nmin_ndot(flags, str, integer, minus);
	free(str);
	return (count);
}
