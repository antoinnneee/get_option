#include "option.h"
#include "get_next_line.h"
#include "libft/includes/libft.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"

char	*get_red_l_opt(char *delim)
{
	char	**line;
	char	*result;
	char	*temp;
	char	*newline;

	newline = ft_strdup("\n");
	line = (char **)ft_memalloc(sizeof(char*));
	result = ft_strnew(1);
	while (get_next_line(0, line) && ft_strcmp(*line, delim))
	{
		temp = ft_strjoin(result, *line);
		free(result);
		result = temp;
		temp = ft_strjoin(result, newline);
		free(result);
		result = temp;
		free(*line);
	}
	free(*line);
	free(newline);
	free(line);
	line = NULL;
	return (result);
}

void	wait_for_cmd(char *param)
{
;
}

void	gnl_statement(int fd, char **line, char **param)
{
	char ** result;

	while (get_next_line(fd, line))
	{
		if (!ft_strcmp(*line, "FIN"))
		{
			free(*line);
			break;
		}
		else if (*line)
		{
			ft_putendl(": ============= :");
			option_parser(ft_strdup(*line));
		}
		/*
		else if (!ft_strcmp(*line, "<<"))
		{
			result = wait_for_cmd(param[1]);
			ft_putendl(result);
			free(result);
			result = NULL;
		}
		*/
		free(*line);
	}
//	free(*line);
	free(line);
	line = NULL;
	f(NULL, 1);
}

int main(int a, char **b)
{
	char **line;

//	ft_putnbr(sizeof(int));
	gnl_statement(0, init_gnl(), b);
//	f(NULL, 0);
	return (0);
}
