/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:53:00 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/06 17:52:55 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_position(t_list **stack_a, int number)
{
	int		position;
	t_list	*temp;

	position = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index == number)
			break ;
		temp = temp->next;
		position++;
	}
	return (position);
}

void	ft_sort_2(t_list **stack_a)
{
	if (stack_is_sorted(stack_a) == 0)
		ft_swap_a(stack_a);
}

void	ft_sort_3(t_list **stack_a)
{
	int	max;
	int	position;

	max = get_max(stack_a);
	position = ft_get_position(stack_a, max);
	if (position == 0)
		ft_rotate_a(stack_a);
	if (position == 1)
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
	}
	if (stack_is_sorted(stack_a) == 0)
		ft_swap_a(stack_a);
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	position;

	min = get_min(stack_a);
	position = ft_get_position(stack_a, min);
	if (position == 1)
		ft_rotate_a(stack_a);
	if (position == 2)
	{
		ft_rotate_a(stack_a);
		ft_rotate_a(stack_a);
	}
	if (position == 3)
		ft_reverse_rotate_a(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	ft_push_to_b(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_push_to_a(stack_a, stack_b);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	position;

	min = get_min(stack_a);
	position = ft_get_position(stack_a, min);
	if (position == 1)
		ft_rotate_a(stack_a);
	if (position == 2)
	{
		ft_rotate_a(stack_a);
		ft_rotate_a(stack_a);
	}
	if (position == 3)
	{
		ft_reverse_rotate_a(stack_a);
		ft_reverse_rotate_a(stack_a);
	}
	if (position == 4)
		ft_reverse_rotate_a(stack_a);
	if (stack_is_sorted(stack_a))
		return ;
	ft_push_to_b(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	ft_push_to_a(stack_a, stack_b);
}
