# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -std=c99
LDFLAGS :=

# Directories
SRC_DIR := src
BUILD_DIR := build

# Source files and objects
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Targets
EXECUTABLE := emulator.exe

# Build rule for the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

# Build rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -rf $(BUILD_DIR)/*.o 
	rm -f $(EXECUTABLE)

