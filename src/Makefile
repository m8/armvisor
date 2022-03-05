# Directories
TARGET_EXEC := armvisor
BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := -I./inc/ -I./arch/ -I./guest_vm

# Compiler settings
CROSS_PREFIX := aarch64-linux-gnu-
CCX := $(CROSS_PREFIX)g++
CC := $(CROSS_PREFIX)gcc
CFLAGS := -c -g $(INC_DIRS)

# Qemu
QEMU := qemu-system-aarch64
GIC_VERSION :=3
MEMORY := 16G
DEVICE := virt,virtualization=on
CPU := cortex-a57

# Wildcards
C_SOURCES = $(shell find . -name '*.c')
ASM_SOURCES = $(shell find . -name '*.S')
C_OBJ = ${C_SOURCES:.c=.o}
ASM_OBJ = ${ASM_SOURCES:.S=.o}


.PHONY: clean
all: qemu-start

.PHONY: clean
clean:
	$(RM) -r ./build/*

debug: qemu-debug

qemu-start: $(TARGET_EXEC)
	$(QEMU) -M $(DEVICE) -machine gic-version=$(GIC_VERSION) -cpu $(CPU) -m $(MEMORY)  -nographic -kernel $(BUILD_DIR)/$(TARGET_EXEC).elf

qemu-debug: $(TARGET_EXEC)
	$(QEMU) -s -S -M $(DEVICE) -machine gic-version=$(GIC_VERSION) -cpu $(CPU) -m $(MEMORY) -nographic -kernel $(BUILD_DIR)/$(TARGET_EXEC).elf

# Link all object files with linker
$(TARGET_EXEC): ${C_OBJ} ${ASM_OBJ}
	$(CROSS_PREFIX)ld -Tmain.ld $(foreach obj,$^,$(BUILD_DIR)/$(obj)) -o $(BUILD_DIR)/$@.elf

# Compile each c files
%.o: %.c
	@ mkdir -p $(BUILD_DIR)/$(dir $@)
	$(CC) $(CFLAGS) $< -o $(BUILD_DIR)/$@

# Compile each asm files
%.o: %.S
	@ mkdir -p $(BUILD_DIR)/$(dir $@)
	$(CROSS_PREFIX)as -c $< -o $(BUILD_DIR)/$@
	