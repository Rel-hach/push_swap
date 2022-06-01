/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:21:52 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/12 01:30:08 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

void	ft_check_instructions(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		ft_push_to_a_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push_to_b_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_swap_a_bonus(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap_b_bonus(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_swap_a_and_b_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate_a_bonus(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate_b_bonus(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rotate_a_and_b_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse_rotate_a_bonus(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse_rotate_b_bonus(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_reverse_rotate_a_and_b_bonus(stack_a, stack_b);
	else
		ft_error();
}

void	ft_print_result(t_list **stack_a, int size)
{
	int	new_size;

	new_size = ft_lstsize(*stack_a);
	if (stack_is_sorted(stack_a) && new_size == size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	apply_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_line(0);
		if (str[0] == '\0')
			break ;
		ft_check_instructions(str, stack_a, stack_b);
		free(str);
	}
	free(str);
}

int	main(int ac, char **av)
{
	char	*s;
	char	**nstr;
	t_list	**stack_a;
	t_list	**stack_b;
	int		size;

	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	if (ac >= 2)
	{
		ft_check_av(av);
		s = ft_join_args(av);
		if (s[0] == ' ')
			return (0);
		nstr = ft_split (s, ' ');
		if (ft_check_ifvalid(nstr) == 1)
			*stack_a = ft_create_stack(nstr);
		size = ft_lstsize(*stack_a);
		apply_instructions (stack_a, stack_b);
		ft_print_result(stack_a, size);
		ft_clear_stack(stack_a, stack_b);
	}
	return (0);
}
