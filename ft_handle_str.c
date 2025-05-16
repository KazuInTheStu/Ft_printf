#include "ft_printf.h"

int	ft_handle_str(char *s, int width, int minus)
{
	int	len;
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	while (!minus && width > len)
	{
		count += write(1, " ", 1);
		width--;
	}
	count += write(1, s, len);
	while (minus && width > len)
	{
		count += write(1, " ", 1);
		width--;
	}
	return (count);
}
