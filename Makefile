SRC = main.c \
      init.c \
      handle_mutex_thread.c \
      parsing_input.c
NAME = philo
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MAGENTA = \033[38;5;213m
RESET = \033[0m
HEADER = "\n$(MAGENTA)\
██████╗ ██╗  ██╗██╗██╗     ██████╗  ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗\n\
██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝\n\
██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗\n\
██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║\n\
██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║\n\
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝\n\
$(RESET)\n"
INCLUDES = philosophers.h

all: $(NAME)

$(NAME): $(OBJ)
	@printf $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "\033[38;5;226mcompiled ✅\n\033[0m"

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@printf "\033[38;5;226mcleaned 🗑️\n\033[0m"

fclean:
	@$(RM) $(NAME) $(OBJ)
	@printf "\033[38;5;226mfully cleaned 🗑️\n\033[0m"

re: fclean all

.PHONY: clean fclean all re
