/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:27:02 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/12 01:35:29 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_stack(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_few_amount(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sort_2(stack_a);
	if (ft_lstsize(*stack_a) == 3)
		ft_sort_3(stack_a);
	if (ft_lstsize(*stack_a) == 4)
		ft_sort_4(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 5)
		ft_sort_5(stack_a, stack_b);
}

void	ft_check_av(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		av[i] = ft_skip_space(av[i]);
		if (av[i][0] == '\0')
			ft_error();
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*s;
	char	**str;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		ft_check_av(av);
		s = ft_join_args(av);
		str = ft_split (s, ' ');
		if (ft_check_ifvalid(str) == 1)
			stack_a = ft_create_stack(str);
		ft_index(&stack_a);
		if (stack_is_sorted(&stack_a))
			return (0);
		if (ft_lstsize(stack_a) < 6)
			ft_few_amount(&stack_a, &stack_b);
		else
			sort_big_numbers(&stack_a, &stack_b);
		ft_clear_stack(&stack_a);
	}
	return (0);
}
