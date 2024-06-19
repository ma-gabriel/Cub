NAME = Cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = -I inc -I libft
DEPS = 

LIBFT = libft/libft.a

SRCS = main.c

SRCS_DIR = $(addprefix srcs/, $(SRCS))
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(HEADER) -Llibft -lft -lreadline

$(OBJS_DIR)/%.o: srcs/%.c $(DEPS)
	mkdir -p objs
	$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(LIBFT):
	cd ./libft && $(MAKE) all

clean:
	rm -rf $(OBJS_DIR)
	cd ./libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && $(MAKE) fclean

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
