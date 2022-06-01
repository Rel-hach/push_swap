/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:06:55 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/09 17:47:23 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **stack_a)
{
	t_list	*t1;
	t_list	*t2;

	if (ft_lstsize(*stack_a) > 1)
	{
		t1 = *stack_a;
		t2 = (*stack_a)->next;
		t1->next = t1->next->next;
		t2->next = *stack_a;
		*stack_a = t2;
		write (1, "sa\n", 3);
	}
}

void	ft_swap_b(t_list **stack_b)
{
	t_list	*t1;
	t_list	*t2;

	if (ft_lstsize(*stack_b) > 1)
	{
		t1 = *stack_b;
		t2 = (*stack_b)->next;
		t1->next = t1->next->next;
		t2->next = *stack_b;
		*stack_b = t2;
		write (1, "sb\n", 3);
	}
}

void	ft_swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		ft_swap_a(stack_a);
		ft_swap_b(stack_b);
		write (1, "ss\n", 3);
	}
}

void	ft_push_to_a(t_list	**stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, temp);
		write (1, "pa\n", 3);
	}
}

void	ft_push_to_b(t_list	**stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, temp);
		write (1, "pb\n", 3);
	}
}
