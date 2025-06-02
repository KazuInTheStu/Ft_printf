NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
OBJDIR = obj

SOURCES = ft_printf.c \
		ft_printf_parse.c \
		ft_printf_conversions.c \
		ft_printf_hex.c \
		ft_printf_utils.c \
		ft_printf_itoa.c \
		ft_printf_bonus.c \
		ft_printf_bonus2.c

BONUS_SOURCES = ft_printf_bonus.c \
				ft_printf_bonus2.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)
BONUS_OBJECTS = $(BONUS_SOURCES:%.c=$(OBJDIR)/%.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re