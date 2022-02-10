#---------------------------------------------------------------------------#

LIBFTPRINTF	:= ../libftprintf.a

#---------------------------------------------------------------------------#

SRCS	:= \
	srcs/D_main.c

B_SRCS	:= \
	srcs/D_main_bonus.c

#---------------------------------------------------------------------------#

NAME	:= test.out
CC		:= gcc
CFLAGS	+= -Wall -Wextra -Werror -g -fsanitize=address
OBJS	= $(SRCS:%.c=%.o)
RM		:= rm -f

ifdef BONUS
SRCS := $(B_SRCS)
endif

#---------------------------------------------------------------------------#

$(NAME): $(OBJS)
ifdef BONUS
	make -C $(dir $(LIBFTPRINTF)) bonus
else
	make -C $(dir $(LIBFTPRINTF))
	touch srcs/D_main_bonus.c
endif
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFTPRINTF):
	make -C $(@D)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus:
	touch srcs/D_main.c
	make BONUS=1

#---------------------------------------------------------------------------#
