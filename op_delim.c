/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_delim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:06:42 by abureau           #+#    #+#             */
/*   Updated: 2017/01/13 15:46:44 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include "libft/includes/libft.h"
#include "get_next_line.h"

int					is_delim(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

static int			unexpected_char(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

static void			copi_statement(char **result, char **line, char **newline)
{
	char	*temp;

	temp = ft_strjoin(*result, *line);
	free(*result);
	*result = temp;
	temp = ft_strjoin(*result, *newline);
	free(*result);
	*result = temp;
	free(*line);
}

char				*gnl_to_char(char *delim)
{
	char	**line;
	char	*result;
	char	*newline;
	char	*temp;

	newline = ft_strdup("\n");
	line = (char **)ft_memalloc(sizeof(char*));
	result = NULL;
	ft_putstr("wait char [\x1B[32m");
	ft_putstr(delim);
	ft_putstr("\x1B[0m] > ");
	while (get_next_line(0, line) && !ft_strstr(*line, delim))
	{
		ft_putstr("wait char [\x1B[32m");
		ft_putstr(delim);
		ft_putstr("\x1B[0m] > ");
		copi_statement(&result, line, &newline);
	}
	temp = ft_strjoin(result, *line);
	free(result);
	free(*line);
	free(newline);
	free(line);
	line = NULL;
	return (temp);
}

static void			add_new_line(char **str)
{
	char	*dest;
	char	*src;

	src = *str;
	dest = ft_strnew(ft_strlen(src) + 2);
	ft_strcpy(dest, src);
	dest[ft_strlen(src)] = '\n';
	src = NULL;
	*str = dest;
}

static void			contoch(char **res, char **trim, int i)
{
	*res = *trim;
	i = 42;
}

char				*continue_to_char(char *str, int *i, int beg, char delim)
{
	char	*trim;
	char	*res;
	char	*result;
	char	del[2];
	char	*newline;

	newline = ft_strdup("\n");
	del[0] = delim;
	del[1] = '\0';
	while (str[*i] != delim && str[*i] != '\0')
		*i = *i + 1;
	trim = ft_strsub(str, beg, *i - 1);
	if (!str[*i])
	{
		res = gnl_to_char(del);
		result = ft_strjoin(newline, res);
		free(res);
		res = ft_strjoin(trim, result);
		free(result);
		free(trim);
	}
	else
		contoch(&res, &trim, (*i = *i + 1));
	free(newline);
	return (res);
}

static int			moulte_test(char *str, int *i, t_word *wd, int *beg)
{
	if (str[*i] == '|' || unexpected_char(str[*i]))
	{
		ft_putendl("parse error near '|, <, >, <<, >>'");
		return (0);
	}
	if (str[*i] == '"')
	{
		*i = *i + 1;
		wd->ddlim = 1;
		wd->dc = '"';
	}
	else if (str[*i] == '\'')
	{
		*i = *i + 1;
		wd->dlim = 1;
		wd->dc = '\'';
	}
	*beg = *i;
	return (1);
}

char				*get_prog_name(char *str, int *cnt, t_word *wod)
{
	char	*trim;
	int		beg;
	char	*result;
	t_word	wd;

	ft_bzero(&wd, sizeof(t_word));
	while (str[wd.i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ';')
		i++;
	if (!moulte_test(str, &i, &wd, &beg))
		return (NULL);
	if (!wd.ddlim && !wd.dlim)
	{
		while (!isblk(str[i]) && (str[i] != '\'' && str[i] != '"'))
			i++;
		trim = ft_strsub(str, beg, i);
		*cnt = i;
		return (trim);
	}
	else
	{
		result = continue_to_char(str, &i, beg, wd.dc);
		trim = ft_strsub(result, 0, ft_strlen(result));
		free(result);
		result = ft_strtrimchar(trim, wd.dc);
		free(trim);
		*cnt = i;
		return (result);
	}
}

int					isblk(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (1);
	return (0);
}
