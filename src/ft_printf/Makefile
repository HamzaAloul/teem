# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 19:39:43 by mabu-are          #+#    #+#              #
#    Updated: 2026/01/26 15:59:12 by mabu-are         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --no-builtin-rules

OBJDIR  := ../../obj/ft_printf
NAME    := $(OBJDIR)/libftprintf.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I.
AR      := ar rcs
RM      := rm -f

# -------------------------
#     SOURCE FILES LIST
# -------------------------
SRCS := ft_printf.c ft_s_putchar.c ft_s_putnbr_u.c ft_s_void.c ft_s_putnbr.c \
                  ft_s_string.c ft_s_puthex.c

OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

# -------------------------
#          COLORS
# -------------------------
BLUE    := $$(printf "\033[34m")
GREEN   := $$(printf "\033[32m")
YELLOW  := $$(printf "\033[33m")
RED     := $$(printf "\033[31m")
RESET   := $$(printf "\033[0m")

# -------------------------
#         RULES
# -------------------------
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)[OK]$(RESET) $(NAME) created"

$(OBJDIR)/%.o: %.c ft_printf.h
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)[CC]$(RESET) $<"

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)[OK]$(RESET) objects removed"

fclean: clean
	@$(RM) $(NAME)
	@rmdir --ignore-fail-on-non-empty $(OBJDIR)
	@echo "$(RED)[OK]$(RESET) $(NAME) removed"

re: fclean all

bonus: all
