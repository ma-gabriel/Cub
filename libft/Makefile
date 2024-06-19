# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geymat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 04:17:20 by geymat            #+#    #+#              #
#    Updated: 2023/11/16 12:56:17 by geymat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c \
       ft_isalpha.c \
       ft_memchr.c  \
       ft_memset.c \
       ft_strlcat.c \
       ft_strrchr.c \
       ft_toupper.c \
       ft_bzero.c \
       ft_isascii.c \
       ft_memcmp.c \
       ft_strchr.c \
       ft_strstr.c \
       ft_calloc.c \
       ft_isdigit.c \
       ft_memcpy.c \
       ft_strdup.c \
       ft_strlen.c \
       ft_substr.c \
       ft_isalnum.c \
       ft_isprint.c \
       ft_memmove.c \
       ft_strjoin.c \
       ft_strncmp.c \
       ft_tolower.c \
       ft_strtrim.c \
       ft_split.c \
       ft_strlcpy.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_strnstr.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c

SRCS_BONUS = ft_lstadd_front_bonus.c \
	     ft_lstnew_bonus.c \
	     ft_lstsize_bonus.c \
	     ft_lstlast_bonus.c \
	     ft_lstadd_back_bonus.c \
	     ft_lstdelone_bonus.c \
	     ft_lstclear_bonus.c \
	     ft_lstiter_bonus.c \
	     ft_lstmap_bonus.c

HEADERS = libft.h

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(RM) $(NAME)

bonus:
	$(MAKE) $(NAME) SRCS="$(SRCS) $(SRCS_BONUS)"

re: fclean
	$(MAKE) all

.PHONY: re all clean fclean bonus
