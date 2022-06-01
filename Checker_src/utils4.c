/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:18:35 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/12 01:36:57 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

void	ft_check_av(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		av[i] = ft_skip_space(av[i]);
		if (av[i][0] == '\0')
			ft_error();
		i++;
	}
}
