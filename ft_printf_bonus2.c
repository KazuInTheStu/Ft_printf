#include "ft_printf.h"

char	*ft_fill_precision(char *new_str, char *s, int zeros, t_flags flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] == '-')
	{
		new_str[i++] = '-';
		j = 1;
	}
	while (zeros > 0)
	{
		new_str[i++] = '0';
		zeros--;
	}
	while (s[j])
	{
		new_str[i++] = s[j++];
	}
	new_str[i] = '\0';
	return (ft_add_prefix(new_str, flags, 'd'));
}

char	*ft_fill_prefix(char *new_str, char *s, t_flags flags, char format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (flags.plus && s[0] != '-' && (format == 'd' || format == 'i'))
		new_str[i++] = '+';
	else if (flags.space && s[0] != '-' && (format == 'd' || format == 'i'))
		new_str[i++] = ' ';
	else if (flags.hash && s[0] != '0' && (format == 'x' || format == 'X'))
	{
		new_str[i++] = '0';
		new_str[i++] = format;
	}
	while (s[j])
	{
		new_str[i++] = s[j++];
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_create_precision_str(char *s, int zeros, t_flags flags, char format)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s);
	new_str = malloc(len + zeros + 1);
	if (!new_str)
		return (s);
	i = 0;
	j = 0;
	if (s[0] == '-')
	{
		new_str[i++] = '-';
		j = 1;
	}
	while (zeros > 0)
	{
		new_str[i++] = '0';
		zeros--;
	}
	while (s[j])
		new_str[i++] = s[j++];
	new_str[i] = '\0';
	return (ft_add_prefix(new_str, flags, format));
}
