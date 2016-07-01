.PHONY: clean All

All:
	@echo "----------Building project:[ vxio - Tux.Debug ]----------"
	@cd "vxio" && "$(MAKE)" -f  "vxio.mk" && "$(MAKE)" -f  "vxio.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ vxio - Tux.Debug ]----------"
	@cd "vxio" && "$(MAKE)" -f  "vxio.mk" clean
