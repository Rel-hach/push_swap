/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:39:03 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/09 22:01:24 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_a_bonus(t_list **stack_a)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 1)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		ft_lstadd_back(stack_a, temp);
	}
}

void	ft_rotate_b_bonus(t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) > 1)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		ft_lstadd_back(stack_b, temp);
	}
}

void	ft_rotate_a_and_b_bonus(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		ft_rotate_a_bonus(stack_a);
		ft_rotate_b_bonus(stack_b);
	}
	if (ft_lstsize(*stack_a) > 1)
		ft_rotate_a_bonus(stack_a);
	if (ft_lstsize(*stack_b) > 1)
		ft_rotate_b_bonus(stack_b);
}
