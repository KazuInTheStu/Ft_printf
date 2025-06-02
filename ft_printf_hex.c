#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format, t_flags flags)
{
	char	*str;
	char	*final_str;
	int		count;

	str = ft_htoa(n, format);
	if (!str)
		return (0);
	final_str = ft_apply_precision_num(str, flags, format);
	count = ft_apply_width(final_str, flags, ft_strlen(final_str));
	free(str);
	if (final_str != str)
		free(final_str);
	return (count);
}

int	ft_print_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += ft_putchar_fd('%', 1);
		count += ft_print_padding(flags.width - 1, ' ');
	}
	else
	{
		if (flags.zero && !flags.dot)
			count += ft_print_padding(flags.width - 1, '0');
		else
			count += ft_print_padding(flags.width - 1, ' ');
		count += ft_putchar_fd('%', 1);
	}
	return (count);
}
