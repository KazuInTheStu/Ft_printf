#include "ft_printf.h"

int	ft_print_char(int c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += ft_putchar_fd(c, 1);
		count += ft_print_padding(flags.width - 1, ' ');
	}
	else
	{
		count += ft_print_padding(flags.width - 1, ' ');
		count += ft_putchar_fd(c, 1);
	}
	return (count);
}

int	ft_print_string(char *s, t_flags flags)
{
	char	*str;
	int		len;
	int		count;

	if (!s)
		s = "(null)";
	str = ft_apply_precision_str(s, flags);
	len = ft_strlen(str);
	count = 0;
	if (flags.minus)
	{
		count += ft_putstr_fd(str, 1);
		count += ft_print_padding(flags.width - len, ' ');
	}
	else
	{
		count += ft_print_padding(flags.width - len, ' ');
		count += ft_putstr_fd(str, 1);
	}
	if (str != s)
		free(str);
	return (count);
}

int	ft_print_pointer(void *ptr, t_flags flags)
{
	char	*hex_str;
	char	*str;
	int		len;
	int		count;

	if (!ptr)
		hex_str = ft_htoa(0, 'x');
	else
		hex_str = ft_htoa((unsigned long)ptr, 'x');
	len = ft_strlen(hex_str) + 2;
	str = malloc(len + 1);
	if (!str)
	{
		free(hex_str);
		return (0);
	}
	str[0] = '0';
	str[1] = 'x';
	str[2] = '\0';
	ft_strcat(str, hex_str);
	count = ft_apply_width(str, flags, len);
	free(str);
	free(hex_str);
	return (count);
}

int	ft_print_decimal(int n, t_flags flags)
{
	char	*str;
	char	*final_str;
	int		count;

	str = ft_itoa(n);
	if (!str)
		return (0);
	final_str = ft_apply_precision_num(str, flags, 'd');
	count = ft_apply_width(final_str, flags, ft_strlen(final_str));
	free(str);
	if (final_str != str)
		free(final_str);
	return (count);
}

int	ft_print_unsigned(unsigned int n, t_flags flags)
{
	char	*str;
	char	*final_str;
	int		count;

	str = ft_utoa(n);
	if (!str)
		return (0);
	final_str = ft_apply_precision_num(str, flags, 'u');
	count = ft_apply_width(final_str, flags, ft_strlen(final_str));
	free(str);
	if (final_str != str)
		free(final_str);
	return (count);
}
