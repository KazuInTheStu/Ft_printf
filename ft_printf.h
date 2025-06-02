#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	has_precision;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, va_list args, int *i);
t_flags	ft_init_flags(void);
t_flags	ft_parse_flags(const char *format, int *i, va_list args);
int		ft_parse_width(const char *format, int *i, va_list args);
int		ft_parse_precision(const char *format, int *i, va_list args);
int		ft_handle_conversion(char c, va_list args, t_flags flags);
int		ft_print_char(int c, t_flags flags);
int		ft_print_string(char *s, t_flags flags);
int		ft_print_pointer(void *ptr, t_flags flags);
int		ft_print_decimal(int n, t_flags flags);
int		ft_print_unsigned(unsigned int n, t_flags flags);
int		ft_print_hex(unsigned int n, char format, t_flags flags);
int		ft_print_percent(t_flags flags);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_htoa(unsigned long n, char format);
int		ft_numlen(long n, int base);
int		ft_unumlen(unsigned long n, int base);
int		ft_print_padding(int width, char pad_char);
int		ft_apply_width(char *str, t_flags flags, int len);
char	*ft_apply_precision_str(char *s, t_flags flags);
char	*ft_apply_precision_num(char *s, t_flags flags, char format);
char	*ft_strcat(char *dest, const char *src);
char	*ft_add_prefix(char *s, t_flags flags, char format);
char	*ft_fill_precision(char *new_str, char *s, int zeros, t_flags flags);
char	*ft_fill_prefix(char *new_str, char *s, t_flags flags, char format);
char	*ft_create_precision_str(char *s, int zeros, t_flags flags, char format);

#endif
