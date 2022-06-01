/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:48:43 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/06 16:48:53 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list **stack_a)
{
	t_list	*t1;
	t_list	*t2;
	int		number;
	int		index;

	t1 = *stack_a;
	t2 = *stack_a;
	while (t1)
	{
		number = t1->number;
		index = 0;
		while (t2)
		{
			if (number > t2->number)
				index++;
			t2 = t2->next;
		}
		t2 = *stack_a;
		t1->index = index;
		t1 = t1->next;
	}
}
