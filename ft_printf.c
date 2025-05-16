#include "ft_printf.h"

static int	ft_dispatch_more(const char **f, va_list args,
	int width, int minus, int zero, int hash)
{
	if (**f == 'x')
		return (ft_handle_hex(va_arg(args, unsigned int), 0,
				width, minus, zero, hash));
	if (**f == 'X')
		return (ft_handle_hex(va_arg(args, unsigned int), 1,
				width, minus, zero, hash));
	if (**f == 'p')
		return (ft_handle_ptr(va_arg(args, unsigned long long), width, minus));
	if (**f == '%')
		return (ft_handle_char('%', width, minus));
	return (0);
}

static int	ft_dispatch(const char **f, va_list args)
{
	int	width;
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hash;

	width = 0;
	minus = 0;
	zero = 0;
	plus = 0;
	space = 0;
	hash = 0;
	ft_parse_flags(f, &width, &minus, &zero, &plus, &space, &hash);
	if (**f == 'c')
		return (ft_handle_char(va_arg(args, int), width, minus));
	if (**f == 's')
		return (ft_handle_str(va_arg(args, char *), width, minus));
	if (**f == 'd' || **f == 'i')
		return (ft_handle_int(va_arg(args, int), width, minus, zero, plus, space));
	if (**f == 'u')
		return (ft_handle_unsigned(va_arg(args, unsigned int),
				width, minus, zero));
	return (ft_dispatch_more(f, args, width, minus, zero, hash));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_dispatch(&format + i, args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
