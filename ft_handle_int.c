#include "ft_printf.h"

int	ft_handle_int(int n, int width, int minus, int zero, int plus, int space)
{
	char	*str;
	int		count;
	int		len;

	count = 0;
	str = ft_itoa(n);
	len = ft_strlen(str);
	if (n >= 0 && (plus || space))
		len++;
	while (!minus && width > len)
	{
		count += write(1, zero ? "0" : " ", 1);
		width--;
	}
	if (n >= 0 && plus)
		count += write(1, "+", 1);
	else if (n >= 0 && space)
		count += write(1, " ", 1);
	count += write(1, str, ft_strlen(str));
	while (minus && width > len)
	{
		count += write(1, " ", 1);
		width--;
	}
	free(str);
	return (count);
}
