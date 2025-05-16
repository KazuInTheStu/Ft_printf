#include "ft_printf.h"

int	ft_parse_flags(const char **f, int *width, int *minus, int *zero, int *plus, int *space, int *hash)
{
	while (**f == '-' || **f == '0' || **f == '+' || **f == ' ' || **f == '#')
	{
		if (**f == '-')
			*minus = 1;
		else if (**f == '0')
			*zero = 1;
		else if (**f == '+')
			*plus = 1;
		else if (**f == ' ')
			*space = 1;
		else if (**f == '#')
			*hash = 1;
		(*f)++;
	}
	while (**f >= '0' && **f <= '9')
	{
		*width = *width * 10 + (**f - '0');
		(*f)++;
	}
	return (0);
}
