NAME = cub3D_bonus
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
	mv $(NAME) ..

-include $(DFILES)

$(BDIR)/%.o : $(SDIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/ $(LIB_INCLUDE)/
	@echo "	$@"

clean	::
	@echo "cleaning $(NAME)";
	@$(RMF) $(OFILES) $(DFILES)

re		::	fclean
	@$(MAKE) -s all

fclean	::	clean
	@$(RMF) ../$(NAME)

force :

include config/forbidden.mk

norm:
	@echo "norminette"
	-@norminette libft/ srcs/ | grep Error
	@echo "comment"
	-@cat $(SFILES) | grep "//"
	@$(MAKE) -s check_forbidden_function

-include config/update.mk

.PHONY: clean re fclean force all norm
