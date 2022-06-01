/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_actions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:06:55 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/11 00:00:53 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_a_bonus(t_list **stack_a)
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
	}
}

void	ft_swap_b_bonus(t_list **stack_b)
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
	}
}

void	ft_swap_a_and_b_bonus(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		ft_swap_a_bonus(stack_a);
		ft_swap_b_bonus(stack_b);
	}
	if (ft_lstsize(*stack_a) > 1)
		ft_swap_a_bonus(stack_a);
	if (ft_lstsize(*stack_b) > 1)
		ft_swap_b_bonus(stack_b);
}

void	ft_push_to_a_bonus(t_list	**stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, temp);
	}
}

void	ft_push_to_b_bonus(t_list	**stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, temp);
	}
}
