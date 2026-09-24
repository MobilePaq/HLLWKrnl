# ==========================================
# HLLWKrnl Makefile for VersatilePB (ARM9)
# ==========================================

# Toolchain configuration
CC      := arm-none-eabi-gcc
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy

# Compiler and assembler flags
CFLAGS  := -mcpu=arm926ej-s -g -Wall -O0 -ffreestanding -Iinclude
ASFLAGS := -mcpu=arm926ej-s -g
LDFLAGS := -T arch/arm926/linker1.ld

# Build artifacts output directory
BUILD_DIR := build

# Project source files based on your directory tree
SRCS_C   := kernel/main.c \
			kernel/uartfunc.c \
            arch/arm926/versatilepb/uart.c
            

SRCS_ASM := arch/arm926/startuparm.s

# Automatically map source files to object files in build/
OBJS := $(addprefix $(BUILD_DIR)/, $(SRCS_ASM:.s=.o) $(SRCS_C:.c=.o))

# Default target
all: $(BUILD_DIR)/kernel.bin

# Convert ELF executable to raw binary image
$(BUILD_DIR)/kernel.bin: $(BUILD_DIR)/kernel.elf
	@echo "  OBJCOPY $@"
	@$(OBJCOPY) -O binary $< $@

# Link all object files together using the linker script
$(BUILD_DIR)/kernel.elf: $(OBJS)
	@echo "  LD      $@"
	@$(LD) $(LDFLAGS) $^ -o $@

# Rule for compiling C source files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "  CC      $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule for assembling Assembly source files (.s extension)
$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@echo "  AS      $<"
	@$(CC) $(ASFLAGS) -c $< -o $@

# Convenience target to run the kernel in QEMU
run: all
	qemu-system-arm -M versatilepb -m 128M -nographic -kernel $(BUILD_DIR)/kernel.bin

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
