#include "option.h"
#include "libft/includes/libft.h"

int	is_cmd_delim(char c)
{
	if (c == '\'' || c == '\"' || c == ';')
		return (TRUE);
	else
		return (FALSE);
}

int	cmd_get_end_unactive(char **line, char del)
{
	int index;

	index = 0;
	while (line[index] && line[index] != del)
	{
		index ++;
	}
}

int	cmd_get_end(char **line)
{
	int index;

	index = 0;
	while (*line[index])
	{
		if (is_cmd_delim(*line[index]))
		{
			if (*line[index] == ';')	
				return (index);
			else
				cmd_get_end_unactive(&line[index+1], line[index]);
		}
		index ++;
	}
}

void	cmd_parser(char *com)
{
	int	index;
	int	end;

	index = 0;
	while (com[index])
	{
		end = cmd_get_end(&com[index]);
		//stock_data();
		if (!com[index])
		{
		}
		index = index + end;
	}
}
