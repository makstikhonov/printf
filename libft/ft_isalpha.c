/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:44:56 by wlakita           #+#    #+#             */
/*   Updated: 2020/11/12 15:21:56 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c <= 'Z' && c >= 'A');
}

static int	ft_islower(int c)
{
	return (c <= 'z' && c >= 'a');
}

int			ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
