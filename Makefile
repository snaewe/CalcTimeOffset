
all: CalcTimeOffset

clean depend generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.CalcTimeOffset $(@)

.PHONY: CalcTimeOffset
CalcTimeOffset:
	@$(MAKE) -f Makefile.CalcTimeOffset all

project_name_list:
	@echo CalcTimeOffset
