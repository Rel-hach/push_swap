/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:58:49 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/10 22:17:50 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_skip_zero(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			str[i - 1] = '-';
		if (str[0] == '+')
			str[i - 1] = '+';
		return (&str[i - 1]);
	}
	return (&str[i]);
}

char	*ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}
