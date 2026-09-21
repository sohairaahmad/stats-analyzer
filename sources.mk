# sources.mk - Target-dependent sources and include paths

ifeq ($(PLATFORM),MSP432)
# Include directory paths for MSP432 Target
INCLUDES = \
	-Iinclude/common \
	-Iinclude/msp432 \
	-Iinclude/CMSIS

# C Source files for MSP432 Target
SOURCES = \
	src/main.c \
	src/memory.c \
	src/interrupts_msp432p401r_gcc.c \
	src/startup_msp432p401r_gcc.c \
	src/system_msp432p401r.c

else
# Include directory paths for HOST Target (default)
INCLUDES = \
	-Iinclude/common

# C Source files for HOST Target
SOURCES = \
	src/main.c \
	src/memory.c

endif
