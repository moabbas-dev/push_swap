NAME = push_swap
BONUS_NAME = checker

FT_PRINTF = ft_printf
FT_PRINTF_LIB = ft_printf/libftprintf.a

SRCS = srcs/mandatory/errors.c         \
       srcs/mandatory/rev_rotate_move.c\
	   srcs/mandatory/sawp_move.c      \
	   srcs/mandatory/sorting_utils2.c \
	   srcs/mandatory/sorting_utils.c  \
	   srcs/mandatory/utils.c          \
	   srcs/mandatory/push_swap.c      \
	   srcs/mandatory/rotate_move.c    \
	   srcs/mandatory/sorting.c        \
	   srcs/mandatory/sorting_utils3.c \
	   srcs/mandatory/stack_utils.c	   \
	   srcs/mandatory/push_move.c	   \

OBJCS = $(SRCS:.c=.o)

SRCS_BONUS = srcs/bonus/checker.c \
			 srcs/mandatory/errors.c         \
			 srcs/mandatory/rev_rotate_move.c\
			 srcs/mandatory/sawp_move.c      \
			 srcs/mandatory/sorting_utils2.c \
			 srcs/mandatory/sorting_utils.c  \
			 srcs/mandatory/utils.c          \
			 srcs/mandatory/rotate_move.c    \
			 srcs/mandatory/sorting.c        \
			 srcs/mandatory/sorting_utils3.c \
			 srcs/mandatory/stack_utils.c	   \
			 srcs/mandatory/push_move.c	  

OBJCS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(FT_PRINTF_LIB)

$(NAME): $(OBJCS) $(OBJCS_BONUS)
	make -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJCS) $(FT_PRINTF_LIB)

bonus: $(OBJCS_BONUS)
	make -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJCS_BONUS) $(FT_PRINTF_LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	make -C $(FT_PRINTF) clean
	rm -f $(OBJCS)
	rm -f $(OBJCS_BONUS)

fclean: clean
	make -C $(FT_PRINTF) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

re_b: fclean bonus

.PHONY: all clean fclean re bonus