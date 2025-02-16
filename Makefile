NAME		= libftprintf.a
CC 			= cc -c -Wall -Wextra -Werror
AR			= ar rcs
INCLUDES	= -I./headers -I./libft/headers
LIBFTDIR	= libft
LIBFT		= $(addprefix $(LIBFTDIR)/, libft.a)
SRC			= ft_printf_bonus.c \
			  print_char.c \
			  print_hex.c \
			  print_nbr.c \
			  print_ptr.c \
			  print_str.c	\
			  print_unsigned.c \
			  utils.c \
			  parsing.c
OBJ 		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

OBJDIR		= obj
SRCDIR		= src
RM			= rm -rf

RED     = \033[0;31m
GREEN   = \033[0;32m
BLUE    = \033[0;34m
YELLOW  = \033[0;33m
BOLD    = \033[1m
RESET   = \033[0m

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(GREEN)ft_printf done!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $< $(INCLUDES) -o $@
	@$(AR) $(NAME) $@

$(LIBFT):
	@make -C $(LIBFTDIR) re
	@cp $(LIBFT) $(NAME)
	@make -C $(LIBFTDIR) fclean

clean :
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)Cleaning $(OBJDIR)...$(RESET)"
	@$(RM) $(OBJDIR)

fclean : clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
