/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_actions_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:39:26 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/09 21:59:08 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_reverse_rotate_a_bonus(t_list **stack_a)
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
	}
}

void	ft_reverse_rotate_b_bonus(t_list **stack_b)
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
	}
}

void	ft_reverse_rotate_a_and_b_bonus(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		ft_reverse_rotate_a_bonus(stack_a);
		ft_reverse_rotate_b_bonus(stack_b);
	}
	if (ft_lstsize(*stack_a) > 1)
		ft_reverse_rotate_a_bonus(stack_a);
	if (ft_lstsize(*stack_b) > 1)
		ft_reverse_rotate_b_bonus(stack_b);
}
