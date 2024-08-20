FFUNCTION = open|close|read|write|printf|malloc|free|perror|strerror|exit

.PHONY: check_forbidden_function
check_forbidden_function:
	@echo "forbidden function"
	@nm -u $(NAME) | egrep -v -w "$(FFUNCTION)"

