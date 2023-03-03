#*******************************************************************************
# Build targets
#*******************************************************************************
.PHONY: all clean Lib Src

all:
	$(MAKE) -C Libraries all
	$(MAKE) -C Src all	
clean:
	$(MAKE) -C Libraries clean
	$(MAKE) -C Src clean
Lib:
	$(MAKE) -C Libraries clean
	$(MAKE) -C Libraries all	
Src:
	$(MAKE) -C Src clean
	$(MAKE) -C Src all
Total: clean all		
