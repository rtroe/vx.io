.PHONY: clean All

All:
	@echo "----------Building project:[ vxpad - Tux.Debug ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxpad.mk"
clean:
	@echo "----------Cleaning project:[ vxpad - Tux.Debug ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxpad.mk" clean
