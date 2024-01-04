NAME = push_swap
PTF = ./utils/ft_printf/libftprintf.a
LBFT = ./utils/libft/libft.a

SRC = push_swap.c push0.c push1.c push2.c push3.c push4.c

RM = rm -rf
CC =  gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(PTF):
	make -C utils/ft_printf
$(LBFT):
	make -C utils/libft

$(NAME): $(SRC) $(LBFT) $(PTF)
	$(CC) $(CFLAGS) $(LBFT) $(PTF) $(SRC) -o $(NAME)   
 
.PHONY: all clean fclean re
	


clean: 
	$(RM) utils/libft/*.o utils/ft_printf/*.o $(OBJCS)

fclean: clean 
	$(RM) $(NAME) $(PTF) $(LBFT)

re: fclean all
