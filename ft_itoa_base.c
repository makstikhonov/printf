/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:27:27 by max               #+#    #+#             */
/*   Updated: 2021/01/19 10:20:57 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_base_length(unsigned long temp_nbr, int base)
{
	int length;

	length = 0;
	if (temp_nbr == 0)
		length++;
	while (temp_nbr > 0)
	{
		temp_nbr /= base;
		length++;
	}
	return (length);
}

char	*ft_itoa_base(unsigned long nbr, int base)
{
	int		length;
	char	*str;

	length = ft_itoa_base_length(nbr, base);
	if ((str = malloc(sizeof(char) * (length + 1))) == NULL)
		return (NULL);
	str[length] = '\0';
	while (length > 0)
	{
		str[length - 1] = nbr % base;
		if (nbr % base > 9)
			str[length - 1] += 'a' - 10;
		else
			str[length - 1] += '0';
		nbr /= base;
		length--;
	}
	return (str);
}
