/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:39:03 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/09 17:46:41 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	if (ft_lstsize(*stack_a) > 1)
	{
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		ft_lstadd_back(stack_a, temp);
		write (1, "ra\n", 3);
	}
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	if (ft_lstsize(*stack_b) > 1)
	{
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		ft_lstadd_back(stack_b, temp);
		write (1, "rb\n", 3);
	}
}

void	ft_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		ft_rotate_a(stack_a);
		ft_rotate_b(stack_b);
		write (1, "rr\n", 3);
	}
}
