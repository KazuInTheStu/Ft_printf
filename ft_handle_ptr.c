#include "ft_printf.h"

int	ft_handle_ptr(unsigned long long p, int width, int minus)
{
	int	count;
	int	len;

	count = 0;
	len = ft_numlen_hex(p) + 2;
	while (!minus && width > len)
	{
		count += write(1, " ", 1);
		width--;
	}
	count += write(1, "0x", 2);
	ft_putnbr_hex_fd(p, "0123456789abcdef", 1);
	while (minus && width > len)
	{
		count += write(1, " ", 1);
		width--;
	}
	return (count + ft_numlen_hex(p));
}
