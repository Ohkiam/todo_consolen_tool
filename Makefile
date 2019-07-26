.PHONY: clean All

All:
	@echo "----------Building project:[ todo_consolen_tool - Debug ]----------"
	@"$(MAKE)" -f  "todo_consolen_tool.mk"
clean:
	@echo "----------Cleaning project:[ todo_consolen_tool - Debug ]----------"
	@"$(MAKE)" -f  "todo_consolen_tool.mk" clean
