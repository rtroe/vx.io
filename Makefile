.PHONY: clean All

All:
	@echo "----------Building project:[ vxpad - Debug ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxpad.mk"
clean:
	@echo "----------Cleaning project:[ vxpad - Debug ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxpad.mk" clean
