
#include "option.h"
#include "libft/includes/libft.h"
#include "get_next_line.h"

int		is_delim(char c)
{
	if (c == '\'' || c == '\"' )
		return (1);
	return (0);
}

static int	unexpected_char(char c)
{
	if (c == '<' || c == '>')
		return 1;
	return 0;
}

static void	copi_statement(char **result, char **line, char **newline)
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

char	*gnl_to_char(char *delim)
{
	char	*temp;
	char	**line;
	char	*result;
	char	*newline;

	newline = ft_strdup("\n");
	line = (char **)ft_memalloc(sizeof(char*));
	result = ft_strnew(1);
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
	result = temp;
//	free(*line);
	free(newline);
	free(line);
	line = NULL;
	return (result);
}

static void		add_new_line(char **str)
{
	char	*dest;
	char	*src;

	src = *str;
	dest = ft_strnew(ft_strlen(src) + 2);
	ft_strcpy(dest, src);
	dest[ft_strlen(src)] = '\n';
//	if (src)
//	free(src);
	src = NULL;
	*str = dest;
}

char	*continue_to_char(char *str, int *i, int beg, char delim)
{
	ft_putendl("begin continue to char");
	char	*trim;
	char	*res;
	char	*result;
	char	del[2];
	char	*newline = ft_strdup("\n");
	del[0] = delim;
	del[1] = '\0';
	while (str[*i] != delim && str[*i] != '\0')
	{
		*i = *i + 1;
	}
	trim = ft_strsub(str, beg, *i - 1);
	if (!str[*i])
	{
		ft_putendl("beg add new line");
		add_new_line(&str);
		ft_putendl("beg gnl_to_char");
		res = gnl_to_char(del);
		res = ft_strjoin(newline, res);
		result = ft_strjoin(trim, res);
		ft_putendl("free res");
		if (res)
			free(res);
		ft_putendl("free res ok , free trim");
		if (trim)
			free(trim);
		ft_putendl("free trim ok");
	}
	else
	{
		result = trim;
		*i = *i + 1;
	}
	ft_putendl("end continue to char");
return (result);
}

char	*get_prog_name(char *str, int *cnt, t_word *wod)
{
	char	*trim;
	int		i;
	int		beg;
	char	*result;
	t_word	wd;

	wd.ddlim = 0;
	wd.dlim = 0;
	ft_putstr("lineread : ");
	ft_putendl(str);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ';' )
		i++;
	if (str[i] == '|' || unexpected_char(str[i]))
	{
		ft_putendl("parse error near '|, <, >, <<, >>'");
		return (NULL);
	}
	if (str[i] == '"')
	{
		i++;
		wd.ddlim = 1;
	}
	else if (str[i] == '\'')
	{
		i++;
		wd.dlim = 1;
	}
	beg = i;
	// (UP) tout les test sont fait
	if (!wd.ddlim && !wd.dlim) // basic case, no complete possible
	{
	ft_putendl("basic case");
		while (!isblk(str[i]) && (str[i] != '\'' && str[i] != '"'))
		{
			i++;
		}
		ft_putstrnb("char from str : " , i);
		trim = ft_strsub(str, beg, i);
		*cnt = i;
		return (trim);
	}
	else if (wd.dlim == 1)
	{
		result = continue_to_char(str, &i, beg, '\'');
		trim = ft_strsub(result, 0, ft_strlen(result));
		free(result);
		result = ft_strtrimchar(trim, '\'');
		free(trim);
		ft_putstrnb("char from str : " , i);
//		if (str[ft_strlen(trim) + 2])
//			result = ft_strjoin(trim, get_prog_name( &str[ft_strlen(trim) + 2], &i, wod));
		*cnt = i;
	return (result);
	}
	else if (wd.ddlim == 1)
	{
		result = continue_to_char(str, &i, beg, '\"');
		trim = ft_strsub(result, 0, ft_strlen(result));
		free(result);
		result = ft_strtrimchar(trim, '"');
		free(trim);
		ft_putstrnb("char from str : " , i);
		*cnt = i;
		return (result);
	}
}

int	isblk(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (1);
	return(0);
}

