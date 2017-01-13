#include "option.h"
#include "libft/includes/libft.h"

int	is_cmd_delim(char c)
{
	if (c == '\'' || c == '\"' || c == ';')
		return (TRUE);
	else
		return (FALSE);
}
