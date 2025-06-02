/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:18:54 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/02 17:35:06 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parse_format(format, args, &i);
		}
		else
		{
			count += ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	ft_parse_format(const char *format, va_list args, int *i)
{
	t_flags	flags;

	flags = ft_parse_flags(format, i, args);
	if (format[*i] && ft_strchr("cspdiuxX%", format[*i]))
	{
		(*i)++;
		return (ft_handle_conversion(format[(*i) - 1], args, flags));
	}
	return (0);
}

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.has_precision = 0;
	return (flags);
}

static t_flags	fthc(t_flags flags, const char *format, int *i, va_list args)
{
	if (format[*i] == '-')
		flags.minus = 1;
	else if (format[*i] == '0')
		flags.zero = 1;
	else if (format[*i] == '.')
	{
		flags.dot = 1;
		(*i)++;
		flags.precision = ft_parse_precision(format, i, args);
		if (flags.precision >= 0)
			flags.has_precision = 1;
		return (flags);
	}
	else if (format[*i] == '#')
		flags.hash = 1;
	else if (format[*i] == ' ')
		flags.space = 1;
	else if (format[*i] == '+')
		flags.plus = 1;
	(*i)++;
	return (flags);
}

t_flags	ft_parse_flags(const char *format, int *i, va_list args)
{
	t_flags	flags;

	flags = ft_init_flags();
	while (format[*i] && ft_strchr("-0.# +", format[*i]))
		flags = fthc(flags, format, i, args);
	flags.width = ft_parse_width(format, i, args);
	return (flags);
}
