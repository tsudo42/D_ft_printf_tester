#---------------------------------------------------------------------------#

LIBFTPRINTF	:= ../libftprintf.a

#---------------------------------------------------------------------------#

SRCS	:= \
	srcs/D_main.c \
	srcs/D_test_no_convert.c \
	srcs/D_test_c.c \
	srcs/D_test_s.c \
	srcs/D_test_p.c \
	srcs/D_test_d.c \
	srcs/D_test_i.c \
	srcs/D_test_u.c \
	srcs/D_test_x.c \

B_SRCS	:= \
	srcs/D_main_bonus.c \

#---------------------------------------------------------------------------#

NAME	:= test.out
CC		:= gcc
CFLAGS	+= -Wall -Wextra -Werror -g -fsanitize=address
OBJS	= $(SRCS:%.c=%.o)
RM		:= rm -f

ifdef MYCFLAG
CFLAGS += $(MYCFLAG)
endif

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
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFTPRINTF)

.PHONY: all
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFTPRINTF):
	make -C $(@D)

.PHONY: clean
clean:
	$(RM) $(OBJS)
	$(RM) $(B_SRCS:%.c=%.o)

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
