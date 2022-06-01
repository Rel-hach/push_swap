/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_several_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:26:04 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/10 22:22:37 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_chunks(t_list **stack_a, t_list **stack_b, t_groups *chunk)
{
	while (ft_lstsize(*stack_a) != 0)
	{
		if ((*stack_a)->index <= chunk->von)
		{
			ft_push_to_b(stack_a, stack_b);
			ft_rotate_b(stack_b);
			chunk->von++;
		}
		else if ((*stack_a)->index <= chunk->von + chunk->bis)
		{
			ft_push_to_b(stack_a, stack_b);
			chunk->von++;
		}
		else
			ft_rotate_a(stack_a);
		if (ft_lstsize(*stack_b) > 2)
		{
			if ((*stack_b)->index < (*stack_b)->next->index)
				ft_swap_b(stack_b);
		}
	}
}

int	get_next_number(t_list *stack_b, t_groups *chunk)
{
	int		size;
	int		position;

	position = 0;
	size = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->index == chunk->von)
			break ;
		stack_b = stack_b->next;
		position++;
	}
	return (position <= (size / 2));
}

void	ft_sort_numbers(t_list **stack_a, t_list **stack_b, t_groups *chunk)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index == chunk->von)
		{
			ft_push_to_a(stack_a, stack_b);
			chunk->von--;
		}
		else if ((get_next_number(*stack_b, chunk)))
			ft_rotate_b(stack_b);
		else
			ft_reverse_rotate_b(stack_b);
	}
}

void	sort_big_numbers(t_list **stack_a, t_list **stack_b)
{
	t_groups	*chunk;

	chunk = malloc(sizeof(chunk));
	if (!chunk)
		exit(0);
	chunk->von = 0;
	chunk->bis = 15;
	if (ft_lstsize(*stack_a) > 250)
		chunk->bis += 17;
	ft_push_chunks(stack_a, stack_b, chunk);
	chunk->von--;
	ft_sort_numbers(stack_a, stack_b, chunk);
	free(chunk);
}
