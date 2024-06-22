NAME = Cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = -I inc -I libft
DEPS = #inc/map_checks.h 

LIBFT = libft/libft.a

SRCS = main.c \
	   check_file.c \
	   get_file.c

SRCS_DIR = $(addprefix srcs/, $(SRCS))
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(HEADER) -Llibft

$(OBJS_DIR)/%.o: srcs/%.c $(DEPS)
	mkdir -p $(OBJS_DIR)
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
