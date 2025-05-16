#include "ft_printf.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

int	ft_numlen_unsigned(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_handle_unsigned(unsigned int n, int width, int minus, int zero)
{
	int	len;
	int	count;

	count = 0;
	len = ft_numlen_unsigned(n);
	while (!minus && width > len)
	{
		count += write(1, zero ? "0" : " ", 1);
		width--;
	}
	ft_putnbr_unsigned_fd(n, 1);
	count += len;
	while (minus && width > len)
	{
		count += write(1, " ", 1);
		width--;
	}
	return (count);
}
