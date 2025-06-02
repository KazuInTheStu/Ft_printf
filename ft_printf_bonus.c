/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:18:26 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/02 13:18:26 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_padding(int width, char pad_char)
{
	int	count;

	count = 0;
	while (width > 0)
	{
		count += ft_putchar_fd(pad_char, 1);
		width--;
	}
	return (count);
}

int	ft_apply_width(char *str, t_flags flags, int len)
{
	int		count;
	char	pad_char;

	count = 0;
	pad_char = ' ';
	if (flags.zero && !flags.minus && !flags.has_precision)
		pad_char = '0';
	if (flags.minus)
	{
		count += ft_putstr_fd(str, 1);
		count += ft_print_padding(flags.width - len, ' ');
	}
	else if (pad_char == '0' && str[0] == '-')
	{
		count += ft_putchar_fd('-', 1);
		count += ft_print_padding(flags.width - len, '0');
		count += ft_putstr_fd(str + 1, 1);
	}
	else
	{
		count += ft_print_padding(flags.width - len, pad_char);
		count += ft_putstr_fd(str, 1);
	}
	return (count);
}

char	*ft_apply_precision_str(char *s, t_flags flags)
{
	char	*new_str;
	int		len;
	int		i;

	if (!flags.has_precision)
		return (s);
	len = ft_strlen(s);
	if (flags.precision >= len)
		return (s);
	new_str = malloc(flags.precision + 1);
	if (!new_str)
		return (s);
	i = 0;
	while (i < flags.precision)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_apply_precision_num(char *s, t_flags flags, char format)
{
	char	*new_str;
	int		len;
	int		zeros;

	len = ft_strlen(s);
	if (!flags.has_precision)
		return (ft_add_prefix(s, flags, format));
	if (flags.precision == 0 && s[0] == '0' && len == 1)
	{
		new_str = malloc(1);
		if (new_str)
			new_str[0] = '\0';
		return (new_str);
	}
	zeros = flags.precision - len;
	if (s[0] == '-')
		zeros = flags.precision - (len - 1);
	if (zeros <= 0)
		return (ft_add_prefix(s, flags, format));
	return (ft_create_p_str(s, zeros, flags, format));
}

char	*ft_add_prefix(char *s, t_flags flags, char format)
{
	char	*new_str;
	int		len;
	int		prefix_len;
	int		is_zero;

	len = ft_strlen(s);
	prefix_len = 0;
	is_zero = (len == 1 && s[0] == '0')
		|| (len == 2 && s[0] == '+' && s[1] == '0')
		|| (len == 2 && s[0] == '-' && s[1] == '0');
	if (flags.plus && s[0] != '-' && (format == 'd' || format == 'i'))
		prefix_len = 1;
	else if (flags.space && s[0] != '-' && (format == 'd' || format == 'i'))
		prefix_len = 1;
	else if (flags.hash && !is_zero && (format == 'x' || format == 'X'))
		prefix_len = 2;
	if (prefix_len == 0)
		return (s);
	new_str = malloc(len + prefix_len + 1);
	if (!new_str)
		return (s);
	return (ft_fill_prefix(new_str, s, flags, format));
}
