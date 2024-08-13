
MLXDIR = mlx
MLXNAME = mlx
MLXAR = minilibx.a
MLXPATH = $(MLXDIR)/$(MLXAR)
MLXINCLUDE = -I $(MLXDIR)/
MLXFTFLAGS = -L $(MLXDIR)/ -l $(MLXNAME) $(MLXINCLUDE) -lXext -lX11

LIB_PATH += $(MLXPATH)
LIB_INCLUDE += $(MLXINCLUDE)
LIB_FLAGS += $(MLXFTFLAGS)
LIB_DIR += $(MLXDIR)

fclean ::
	@echo "clean mlx";
	$(MAKE) clean -C $(MLXDIR)

$(MLXPATH) : force 
	@echo "compiling mlx";
	$(MAKE) -C $(MLXDIR)
	@echo "mlx compilation done";
