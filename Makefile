.PHONY: clean All

All:
	@echo "----------Building project:[ vxio - Win.Release ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxio.mk"
clean:
	@echo "----------Cleaning project:[ vxio - Win.Release ]----------"
	@cd "vxpad" && "$(MAKE)" -f  "vxio.mk" clean
