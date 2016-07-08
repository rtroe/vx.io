.PHONY: clean All

All:
	@echo "----------Building project:[ vxio - Win.Debug ]----------"
	@cd "vxio" && "$(MAKE)" -f  "vxio.mk" && "$(MAKE)" -f  "vxio.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ vxio - Win.Debug ]----------"
	@cd "vxio" && "$(MAKE)" -f  "vxio.mk" clean
