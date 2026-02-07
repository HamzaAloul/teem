NAME    := push_swap

CC      := cc
CFLAGS  := -Wall -Wextra -Werror

SRCDIR  := src
OBJROOT := obj
OBJDIR  := $(OBJROOT)/push_swap

LIBFT_DIR   := $(SRCDIR)/libft
PRINTF_DIR  := $(SRCDIR)/ft_printf

LIBFT_A     := $(OBJROOT)/libft/libft.a
PRINTF_A    := $(OBJROOT)/ft_printf/libftprintf.a

INC     := -I include -I $(LIBFT_DIR) -I $(PRINTF_DIR)

SRC :=  push_swap_main.c \
        move_p.c \
        move_r.c \
        move_rr.c \
        move_s.c \
        stacks_put_and_free.c \
	compute_disorder.c \
	duplicate_error.c \
	len_arr.c \
	not_int_error.c

OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

RM := rm -rf

# -------------------------
#          COLORS
# -------------------------
BLUE    := $$(printf "\033[34m")
GREEN   := $$(printf "\033[32m")
YELLOW  := $$(printf "\033[33m")
RED     := $$(printf "\033[31m")
RESET   := $$(printf "\033[0m")

# -------------------------
#           RULES
# -------------------------

.PHONY: all clean fclean re libs

all: libs $(NAME)

# -------- LIBS --------
libs:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(GREEN)[OK]$(RESET) libraries compiled"

# -------- MAIN --------
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) -o $@
	@echo "$(GREEN)[OK]$(RESET) $(NAME) created"

# -------- OBJECTS --------
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "$(BLUE)[CC]$(RESET) $<"

# -------- CLEAN --------
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) $(OBJDIR)
	@echo "$(YELLOW)[OK]$(RESET) push_swap objects removed"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)[OK]$(RESET) binary removed"

re: fclean all
