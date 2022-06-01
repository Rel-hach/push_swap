/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:55:01 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/12 01:29:37 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_wordscounter(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	*ft_write_words(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		ft_strlcpy(str, s, i + 1);
		return (str);
	}
	return (NULL);
}

static char	**ft_freestr(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		nb_words;
	char	**tdstr;

	if (s)
	{
		nb_words = ft_wordscounter(s, c);
		tdstr = (char **)malloc(sizeof(char *) * (nb_words + 1));
		if (!tdstr)
			return (NULL);
		i = -1;
		while (++i < nb_words)
		{
			while (*s == c)
				s++;
			tdstr[i] = ft_write_words(s, c);
			if (!tdstr[i])
				return (ft_freestr(tdstr));
			s = s + ft_strlen(tdstr[i]);
		}
		tdstr[i] = 0;
		return (tdstr);
	}
	return (NULL);
}

void	ft_clear_stack(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (!*lst1 && !*lst2)
		return ;
	if (*lst2)
	{
		while (*lst2 != NULL)
		{
			temp = *lst2;
			*lst2 = (*lst2)->next;
			free(temp);
		}
	}
	while (*lst2 != NULL)
	{
		temp = (*lst2)->next;
		free(*lst2);
		*lst2 = temp;
	}
}
