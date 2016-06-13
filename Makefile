.PHONY: clean All

All:
	@echo "----------Building project:[ vxpad - Release ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxpad.mk"
clean:
	@echo "----------Cleaning project:[ vxpad - Release ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxpad.mk" clean
