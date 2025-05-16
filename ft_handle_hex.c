#include "ft_printf.h"

int	ft_numlen_hex(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_hex_fd(unsigned long n, char *base, int fd)
{
	if (n >= 16)
		ft_putnbr_hex_fd(n / 16, base, fd);
	ft_putchar_fd(base[n % 16], fd);
}

int	ft_handle_hex(unsigned int n, int caps, int width, int minus, int zero, int hash)
{
	char	*base;
	int		len;
	int		count;

	count = 0;
	base = (caps == 1) ? "0123456789ABCDEF" : "0123456789abcdef";
	len = ft_numlen_hex(n);
	if (hash && n != 0)
		len += 2;
	while (!minus && width > len)
	{
		count += write(1, zero ? "0" : " ", 1);
		width--;
	}
	if (hash && n != 0)
		count += write(1, caps ? "0X" : "0x", 2);
	ft_putnbr_hex_fd(n, base, 1);
	count += ft_numlen_hex(n);
	while (minus && width > len)
	{
		count += write(1, " ", 1);
		width--;
	}
	return (count);
}
