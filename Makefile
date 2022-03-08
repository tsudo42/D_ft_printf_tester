# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 23:50:33 by tsudo             #+#    #+#              #
#    Updated: 2022/03/08 15:39:39 by tsudo            ###   ##########         #
#                                                                              #
# **************************************************************************** #

TARGET	:= ../libftprintf.a

# **************************************************************************** #

NAME	:= test.out
B_NAME	:= test_bonus.out
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP -g -fsanitize=address
RM		:= rm -f

# **************************************************************************** #

SRCS	+= $(M_SRCS)
M_SRCS	:= \
	srcs/D_main.c \

SRCS	+= $(U_SRCS)
U_SRCS	:= \
	srcs/D_test_u.c \
	srcs/D_test_i.c \
	srcs/D_test_c.c \
	srcs/D_test_x.c \
	srcs/D_test_d.c \
	srcs/D_test_s.c \
	srcs/D_test_p.c \
	srcs/D_test_no_convert.c \
	srcs/D_test_hand.c \

SRCS	+= $(B_SRCS)
B_SRCS	:= \
	srcs/D_main_bonus.c \

INCS	:= \
	includes \

# **************************************************************************** #

M_OBJS	= $(patsubst %.c,objs/%.o, $(notdir $(M_SRCS)))
U_OBJS	= $(patsubst %.c,objs/%.o, $(notdir $(U_SRCS)))
B_OBJS	= $(patsubst %.c,objs/%.o, $(notdir $(B_SRCS)))
OBJS	= $(M_OBJS) $(U_OBJS) $(B_OBJS)
DEPS	= $(OBJS:.o=.d)
CFLAGS	+= $(addprefix -I,$(INCS))
vpath %.c $(sort $(dir $(SRCS)))

CFLAGS	+= $(MYCFLAGS)

# **************************************************************************** #

$(NAME): $(M_OBJS) $(U_OBJS) $(TARGET)
	$(CC) $(CFLAGS) -o $@ $^

$(B_NAME): $(B_OBJS) $(U_OBJS) $(TARGET)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET):
	make -C $(@D)

.PHONY: all
all: $(NAME)

.PHONY: _all
_all: $(NAME) $(B_NAME)

-include $(DEPS)

objs/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make -C $(@D)

.PHONY: clean
clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME) $(B_NAME)

.PHONY: fclean_target
fclean_target:
	make fclean -C $(dir $(TARGET))

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(B_NAME)

# **************************************************************************** #
