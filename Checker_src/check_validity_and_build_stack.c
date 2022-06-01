/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_and_build_stack.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:08:31 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/10 22:21:23 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_repeat(int number, char **str, int i)
{
	i++;
	while (str[i])
	{	
		if (ft_atoi(str[i]) == number)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
			i++;
	}
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		ft_error();
	return (1);
}

char	*ft_join_args(char **av)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup(av[i]);
	i++;
	while (av[i])
	{
	str = ft_strjoin(str, " ");
	str = ft_strjoin(str, av[i]);
	i++;
	}
	return (str);
}

int	ft_check_ifvalid(char **str)
{
	int	i;
	int	number;

	i = 0;
	while (str[i])
	{
		number = ft_atoi(str[i]);
		if (ft_is_number(str[i]) == 0
			|| ft_is_repeat(number, str, i) == 0
			|| (ft_strlen(ft_skip_zero(str[i])) > 10 && str[i][0] != '-'))
			ft_error();
		if (ft_strlen(ft_skip_zero(str[i])) >= 10)
		{
			if (ft_strcmp("2147483647", ft_skip_zero(str[i])) < 0)
				ft_error();
			if (str[i][0] == '-')
			{
				if (ft_strcmp("-2147483648", ft_skip_zero(str[i])) < 0
					|| ft_strlen(str[i]) > 11)
					ft_error();
			}
		}
		i++;
	}
	return (1);
}

t_list	*ft_create_stack(char **str)
{
	t_list	*new;
	t_list	*list;
	int		i;

	i = 0;
	list = ft_lstnew(ft_atoi(str[i]));
		i++;
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		ft_lstadd_back(&list, new);
		i++;
	}
	ft_free(str);
	free(str);
	return (list);
}
