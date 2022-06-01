/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:39:26 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/09 17:47:00 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack_a;
	temp2 = *stack_a;
	if (ft_lstsize(*stack_a) > 1)
	{
		while (temp->next)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = NULL;
		ft_lstadd_front(stack_a, temp);
		write (1, "rra\n", 4);
	}
}

void	ft_reverse_rotate_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;
	t_list	*new;

	temp = *stack_b;
	temp2 = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		while (temp->next)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = NULL;
		new = temp;
		ft_lstadd_front(stack_b, new);
		write (1, "rrb\n", 4);
	}
}

void	ft_reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		ft_reverse_rotate_a(stack_a);
		ft_reverse_rotate_b(stack_b);
		write (1, "rrr\n", 4);
	}
}
