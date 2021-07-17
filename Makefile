NAME = libftprintf.a

SRC = ft_printf.c ft_itoa.c ft_itoa_p.c parse_str_d.c parse_str_c.c \
		parse_str_u.c parse_str_p.c parse_str_x.c  \
    	ft_itoa_u.c ft_itoa_x.c ft_printf_utils.c \
		ft_printf_utils2.c parse_str_s.c parse_str_proc.c \

OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -f

BONUS = ft_printf.c ft_itoa.c ft_itoa_p.c parse_str_d.c parse_str_c.c \
		parse_str_u.c parse_str_p.c parse_str_x.c  \
    	ft_itoa_u.c ft_itoa_x.c ft_printf_utils.c \
		ft_printf_utils2.c parse_str_s.c parse_str_proc.c \

BONUSOBJS = $(BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:	$(NAME)

%.o: %.c	$(HEADER)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJ)	

fclean: clean
		$(RM) $(NAME)

re: fclean all

rebonus:	fclean bonus

.PHONY : all clean fclean re bonus rebonus