#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

// Main printf
int		ft_printf(const char *format, ...);

// Dispatcher
int		ft_dispatch(const char **f, va_list args);
int		ft_dispatch_more(const char **f, va_list args,
			int width, int minus, int zero, int hash);

// Handlers
int		ft_handle_char(char c, int width, int minus);
int		ft_handle_str(char *s, int width, int minus);
int		ft_handle_int(int n, int width, int minus,
			int zero, int plus, int space);
int		ft_handle_unsigned(unsigned int n,
			int width, int minus, int zero);
int		ft_handle_hex(unsigned int n, int caps,
			int width, int minus, int zero, int hash);
int		ft_handle_ptr(unsigned long long p, int width, int minus);

// Utils
int		ft_parse_flags(const char **f, int *width, int *minus,
			int *zero, int *plus, int *space, int *hash);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr_hex_fd(unsigned long n, char *base, int fd);
int		ft_numlen_unsigned(unsigned int n);
int		ft_numlen_hex(unsigned long n);

#endif
