
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
	char	**line;
	char	*result;
	char	*newline;

	newline = ft_strdup("\n");
	line = (char **)ft_memalloc(sizeof(char*));
	result = ft_strnew(1);
	while (get_next_line(0, line) && !ft_strstr(*line, delim))
	{
		copi_statement(&result, line, &newline);
	}
	copi_statement(&result, line, &newline);

//	free(*line);
	free(newline);
	free(line);
	line = NULL;
	return (result);
}

char	*continue_to_char(char *str, int *i, int beg, char delim)
{
	char	*trim;
	char	*res;
	char	*result;
	char	del[2];

	del[0] = delim;
	del[1] = '\0';
	while (str[*i] != delim && str[*i] != '\0')
	{
		*i = *i + 1;
	}
	if (str[*i] == delim)
		trim = ft_strsub(str, beg, *i - 1);
	else
		trim = ft_strsub(str, beg, *i);
	if (!str[*i])
	{
		res = gnl_to_char(del);
		result = ft_strjoin(trim, res);
		free(res);
		free(trim);
	}
	else
		result = trim;
	return (result);
}

char	*get_prog_name(char *str, int *cnt, t_word *wd)
{
	char	*trim;
	int		i;
	int		beg;
	char	*res;
	char	*result;

	ft_putstr("lineread : ");
	ft_putendl(str);
	i = *cnt;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ';' )
		i++;
	if (str[i] == '|' || unexpected_char(str[i]))
	{
		ft_putendl("parse error near '|, <, >, <<, >>'");
		return (NULL);
	}
	if (str[i] == '"')
	{
		wd->ddlim = 1;
		i++;
	}
	else if (str[i] == '\'')
	{
		wd->dlim = 1;
		i++;
	}
	beg = i;
	// (UP) tout les test sont fait
	if (!(wd->ddlim || wd->dlim)) // basic case, no complete possible
	{
		while (!isblk(str[i]))
		{
			i++;
		}
		trim = ft_strsub(str, beg, i);
	}
	else if (wd->dlim == 1)
	{
		result = continue_to_char(str, &i, beg, '\'');
		trim = ft_strsub(result, 0, ft_strlen(result));
		ft_putendl(result);
		ft_putendl(trim);
		return (trim);
	}
	else if (wd->ddlim == 1)
	{
		while (str[i] != '\"' && str[i] != '\0')
		{
			i++;
		}
		trim = ft_strsub(str, beg, i - 1);
		if (!str[i])
		{
			res = get_red_l_opt("\"");
			result = ft_strjoin(trim, res);
			free(res);
			free(trim);
		}
		else
		{
			result = trim;
		}
		return (result);
	}
}

int	isblk(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (1);
	return(0);
}

