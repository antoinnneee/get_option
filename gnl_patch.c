/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_patch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:24:42 by abureau           #+#    #+#             */
/*   Updated: 2016/11/20 13:24:44 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft/includes/libft.h"

char	**init_gnl()
{
	char **line;

	line = (char**)ft_memalloc(sizeof(char*));
	f(line, 0);
	return (line);
}


int				ff(char **line, int i)
{
	static char	**tmp;

	if (i)
	{
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	else
		tmp = line;
	return (i);
}

int				f(char **line, int i)
{
	static char	**tmp;

	if (i)
	{
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	else
		tmp = line;
	return (i);
}
int				fb(char ***line, int i)
{
	static char	***tmp;

	if (i)
	{
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	else
		tmp = line;
	return (i);
}
