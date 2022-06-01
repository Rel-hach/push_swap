/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:53:22 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/10 17:17:38 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// libraries:
# include <fcntl.h>
# include <unistd.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
}				t_list;

// Utils:

int		ft_atoi(char	*str);
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *s);
char	*gnl(int fd);
int		ft_is_repeat(int number, char **str, int i);
int		ft_is_number(char *str);
char	*ft_join_args(char **av);
int		ft_check_ifvalid(char **str);
t_list	*ft_create_stack(char **str);
void	ft_clear_stack(t_list **lst1, t_list **lst2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_lenstr(const char *s);
char	*get_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_skip_zero(char *str);

// lists:

t_list	*ft_lstnew(int number);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

//push_swap_actions:

void	ft_swap_a_bonus(t_list **stack_a);
void	ft_swap_b_bonus(t_list **stack_b);
void	ft_swap_a_and_b_bonus(t_list **stack_a, t_list **stack_b);
void	ft_push_to_a_bonus(t_list	**stack_a, t_list **stack_b);
void	ft_push_to_b_bonus(t_list	**stack_a, t_list **stack_b);

//rotate_and_reverse_rotate_actions:

void	ft_rotate_a_bonus(t_list **stack_a);
void	ft_rotate_b_bonus(t_list **stack_b);
void	ft_rotate_a_and_b_bonus(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_a_bonus(t_list **stack_a);
void	ft_reverse_rotate_b_bonus(t_list **stack_b);
void	ft_reverse_rotate_a_and_b_bonus(t_list **stack_a, t_list **stack_b);

// utils 

int		stack_is_sorted(t_list **stack_a);
void	ft_error(void);
void	ft_free(char **str);
int		ft_isdigit(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_check_av(char **av);
char	*ft_skip_space(char *str);

#endif
