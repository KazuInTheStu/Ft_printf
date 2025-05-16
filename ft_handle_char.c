#include "ft_printf.h"

int	ft_handle_char(char c, int width, int minus)
{
	int	count;

	count = 0;
	while (!minus && width > 1)
	{
		count += write(1, " ", 1);
		width--;
	}
	count += write(1, &c, 1);
	while (minus && width > 1)
	{
		count += write(1, " ", 1);
		width--;
	}
	return (count);
}
