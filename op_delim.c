
#include "option.h"
#include "libft/includes/libft.h"

int		is_delim(char c)
{
	if (c == '\'' || c == '\"' )
		return (1);
	return (0);
}

char	*get_prog_name(char *str, int *cnt, t_word *wd)
{
	char	*trim;
	int		i;
	int		beg;

	while (str[i] == ' ' | str[i] == '\t' | str[i] == '\n' | str[i] == ';' )
		i++;
	if (str[i] == '|')
	{
		ft_putendl("parse error near '|'");
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
	if (!(wd->ddlim || wd->dlim))
	{
		while (!isblk(str[i]))
		{
			i++;
		}
		trim = ft_strsub(str, beg, i);
	}
}

int	isblk(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return(0);
}

