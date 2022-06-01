/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:17:57 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/07 17:03:18 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

int	ft_atoi(char *str)
{
	int		i;
	int		j;
	int		sign;
	int		n;

	i = 0;
	j = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

int	get_min(t_list **stack_a)
{
	t_list	*temp;
	int		min;

	temp = *stack_a;
	min = 4;
	while (temp)
	{
		if (min > temp->index)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

int	get_max(t_list **stack_a)
{
	t_list	*temp;
	int		max;

	temp = *stack_a;
	max = 0;
	while (temp)
	{
		if ((max < temp->index))
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}
