/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:35:12 by abureau           #+#    #+#             */
/*   Updated: 2017/01/11 14:59:50 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

# define OP_RESET 0
# define OP_READ 2
# define OP_WRITE 3

# define O_D_RED 1U << 2
# define O_L_RED 1U << 1
# define O_R_RED 1U << 0

# define O_PIPED 1U << 3
# define O_SEPAR 1U << 4

# define R7OPT op_flags(OP_WRITE, OP_RESET)

/*
**	reset flags with OP_WRITE, and OP_RESET
**	O_D_RED, available only if O_L_RED || O_R_RED. O_D_RED mean Double REDir
**	O_PIPED, pipe symbol found '|'
**	O_SEPAR, separator symbol found ';'
*/

typedef struct		s_com{
	int				is_piped;
char			*prog;
	char			**param;
	char			**option;
	struct s_com	*next;
}					t_com;

typedef struct		s_word{
	int				ddlim;
	int				dlim;
	int				esc;
	char			*mot;
}					t_word;

int					fb(char ***line, int i);
int					f(char **line, int i);
int					ff(char **line, int i);
char				**init_gnl();
void				cmd_parser(char **line);
int					get_end_pos(char *line);
char				*get_prog_name(char *str, int *cnt, t_word *wd);
int					op_flags(int state, int val);
void				option_parser(char *line_cpy);
void				push_back_com(t_com **head, t_com *elem);
int					is_delim(char c);
int					isblk(char c);
char				*get_red_l_opt(char *delim);

#endif
