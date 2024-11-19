BONUSDIR = bonus/

bonus::	force
	@echo "compiling bonus";
	@$(MAKE) -C $(BONUSDIR);
	@echo "bonus compilation done";

fclean ::
	@echo "clean bonus";
	@$(MAKE) fclean -C $(BONUSDIR);

.PHONY: bonus