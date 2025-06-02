#include "ft_printf.h"

int	ft_parse_width(const char *format, int *i, va_list args)
{
	int	width;

	width = 0;
	if (format[*i] == '*')
	{
		width = va_arg(args, int);
		(*i)++;
	}
	else
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			width = width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	return (width < 0 ? 0 : width);
}

int	ft_parse_precision(const char *format, int *i, va_list args)
{
	int	precision;

	precision = 0;
	if (format[*i] == '*')
	{
		precision = va_arg(args, int);
		(*i)++;
		if (precision < 0)
			precision = -1;
	}
	else
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			precision = precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	return (precision);
}

int	ft_handle_conversion(char c, va_list args, t_flags flags)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int), flags));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *), flags));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *), flags));
	else if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(args, int), flags));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int), flags));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c, flags));
	else if (c == '%')
		return (ft_print_percent(flags));
	return (0);
}
