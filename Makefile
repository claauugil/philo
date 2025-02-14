SRC = philosophers.c \
	  main.c \
	  utils.c\
	  parsing_input \

NAME = philosophers

OBJ = $(SRC:.c=.o)

INCLUDES = philosophers.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)
	@printf "ok 👍🏻\n"

$(NAME) : $(OBJ)
	"$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@(RM) $(OBJ)
	@printf "cleaned 🗑️"

fclean: clean
	@(RM) $(NAME)
	@printf "fully cleaned	@echo "cleaned 🗑️✅"

re: fclean all

.PHONY: clean fclean all re
