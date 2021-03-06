
#include <stdio.h>
#include "option.h"
#include "libft/includes/libft.h"

t_com	*init_com()
{
	t_com	*new;

	new = (t_com*)ft_memalloc(sizeof(t_com));
	new->is_piped = 0;
	new->prog = NULL;
	new->param = NULL;
	new->option = NULL;
	new->next = NULL;
	return (new);
}

t_com	built_word(char *str, int *cnt, t_com **cmd, t_word *wd)
{
char del;
	while (str[*cnt])
	{
		if (is_delim(str[*cnt]))
		{
			if (str[*cnt] != del)
			{
//				ignore continue reading;
			}
		}
//		if (is_spechar(str[*cnt]))
//		{
			
//		}
		*cnt++;
		//		build_word(str, &index);
	}
}

t_com	*get_option(char *str, int *cnt)
{
	t_com	*head;
	int		stop;
	t_word	wd;
	t_com	*elem;
	long	test;

	ft_bzero(&wd, sizeof(t_word));
	if (!str)
		return (NULL);
	head = init_com();
	elem = init_com();
	ft_putendl("init complete");
	if (!head)
		return (NULL);
	while (str[*cnt])
	{
		R7OPT;
		
		elem->prog = get_prog_name(str, cnt, &wd);
		ft_putstr("Resultat -->");
		ft_putnbrnl(*(int*)(elem));
		ft_putendl((char*)*(&elem + 8));
		
		break;
//built_word(str, cnt, &elem, &wd);
	}
	return (head);
}

int		op_flags(int state, int val)
{
	static int	flag_saver = 0;

	if (state == OP_WRITE)
	{
		if (val == OP_RESET)
			flag_saver = 0;
		else
			flag_saver = flag_saver | val;
	}
	else if (state == OP_READ)
	{
		if (flag_saver & val)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	option_parser(char	*line_cpy)
{
	t_com	*result;
	t_com	*elem;
	int		index;
	int		cnt;

	index = 0;
	cnt = 0;
	while (line_cpy)
	{
		elem = get_option(&line_cpy[index], &cnt);
		index = index + cnt;
		cnt = 0;
		break;
	}
}

void	push_back_com(t_com **head, t_com *elem)
{
	t_com	*tmp;

	tmp = *head;
	if (!head)
	{
		*head = elem;
		return ;
	}
	while (tmp)
	{
		tmp = tmp->next;
		if (!tmp)
		{
			tmp = elem;
			return;
		}
	}
}


