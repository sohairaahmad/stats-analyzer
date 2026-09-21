# Makefile for C1M2 Assessment
include sources.mk

# Default platform setup
PLATFORM ?= HOST
TARGET = c1m2

# General C Flags (Common to both platforms)
GENERAL_FLAGS = -Wall -Werror -g -O0 -std=c99

# Platform-Specific Setup
ifeq ($(PLATFORM),MSP432)
	# Target Compiler & Tools
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump

	# Architecture Flags for ARM Cortex-M4
	ARCH_FLAGS = -mcpu=cortex-m4 \
	             -mthumb \
	             -march=armv7e-m \
	             -mfloat-abi=hard \
	             -mfpu=fpv4-sp-d16 \
	             --specs=nosys.specs

	# Platform Specific Flags
	PLATFORM_FLAGS = -DMSP432
	LINKER_FILE = msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

else
	# Host Compiler & Tools
	CC = gcc
	SIZE = size
	OBJDUMP = objdump

	ARCH_FLAGS = 
	PLATFORM_FLAGS = -DHOST
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif

# Combine Preprocessor and Compiler Flags
CPPFLAGS = $(PLATFORM_FLAGS) $(INCLUDES) -MD -MP
CFLAGS = $(GENERAL_FLAGS) $(ARCH_FLAGS) $(CPPFLAGS)

# Object, Dependency, Assembly, Preprocessor Output Lists
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PREPS = $(SOURCES:.c=.i)

# Include generated dependency files
-include $(DEPS)

# Rules / Targets

.PHONY: compile-all build clean

# 1. Preprocessed output generation (%.i)
%.i: %.c
	$(CC) -E $< $(CFLAGS) -o $@

# 2. Assembly code generation from C source (%.asm)
%.asm: %.c
	$(CC) -S $< $(CFLAGS) -o $@

# 3. Disassemble output binary or object file into assembly
$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -D $(TARGET).out > $(TARGET).asm

# 4. Object file generation (%.o)
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

# 5. Compile all object files without linking
compile-all: $(OBJS)

# 6. Full build: Compile, Link, and Report Size
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

# 7. Clean up all build artifacts
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREPS) $(TARGET).out $(TARGET).map $(TARGET).asm
