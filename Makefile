NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_control.c ft_printf.c ft_puts.c ft_printf.c
OBJS = $(SRCS:.c=.o)

RESET   = \033[0m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
CYAN    = \033[1;36m
RED     = \033[1;31m

all: $(NAME)
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN) $(NAME) is CREATED!$(RESET)"

clean: $(OBJS)
	@rm -rf $(OBJS)
	@echo "$(RED) Objects are DELETED!$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) $(NAME) is DELETED!$(RESET)"

re: fclean all

.PHONY: all clean fclean re