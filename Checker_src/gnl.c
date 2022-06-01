/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:49:01 by rel-hach          #+#    #+#             */
/*   Updated: 2022/04/07 15:47:01 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_line(int fd)
{
	char	str[99999];
	char	buffer[1];
	int		i;

	i = 0;
	while (read(fd, buffer, 1) > 0)
	{
		str[i++] = buffer[0];
		if (buffer[0] == '\n')
			break ;
	}
	str[i] = '\0';
	return (ft_strdup(str));
}
