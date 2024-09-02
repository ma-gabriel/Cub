NAME = cub3D
ARGS = 
CC = cc
RMF = rm -f

CFLAGS = -g -Wall -Wextra -Werror
DFLAGS = -MP -MMD

SDIR = srcs
BDIR = .build
DDIR = $(BDIR)
HDIR = includes

LIB_PATH :=
LIB_DIR :=
LIB_INCLUDE :=
LIB_FLAGS :=

SRCS :=

SFILES = $(SRCS:%=$(SDIR)/%)

DFILES = $(SRCS:%.c=$(DDIR)/%.d)

OFILES = $(SRCS:%.c=$(BDIR)/%.o)

LIB_FLAGS := -l m

all:
	@echo "compiling $(NAME):"
	@$(MAKE) -s $(NAME)

bonus:	all

include config/libft.mk
include config/libmlx.mk
include config/srcs.mk

$(NAME) : $(OFILES) | $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIB_FLAGS)
	@echo "$(NAME) compilation done";

-include $(DFILES)

$(BDIR)/%.o : $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/ $(LIB_INCLUDE)/
	@echo "	$@"

clean	::
	@echo "cleaning $(NAME)";
	@$(RMF) $(OFILES) $(DFILES)

re		::	fclean
	@$(MAKE) -s all

fclean	::	clean
	@$(RMF) $(NAME)

force :

run: all
	@echo "run __$(NAME)__"
	@./$(NAME) $(ARGS)

valgrind: all
	@echo "valgrind __$(NAME)__" 
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(ARGS)

cachegrind: all
	@echo "cachegrind __$(NAME)__" 
	@valgrind --tool=cachegrind --cachegrind-out-file=out ./$(NAME) $(ARGS)

out: $(NAME)
	$(MAKE) cachegrind

annotate: out
	@cg_annotate ./out

time: all
	@echo "time __$(NAME)__"
	@time ./$(NAME) $(ARGS)

include config/forbidden.mk

norm:
	@echo "norminette"
	-@norminette libft-1.2/ srcs/ | grep Error
	@echo "comment"
	-@cat $(SFILES) | grep "//"
	@$(MAKE) -s check_forbidden_function

-include config/update.mk

.PHONY: clean re fclean force all norm run valgrind bonus time cachegrind annotate
