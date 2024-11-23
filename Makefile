CC = clang

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

OUT_DIR_BUILD   = build
OUT_DIR_RELEASE = release
OUT_NAME        = $(OUT_DIR_BUILD)/martoon

CFLAGS         = -Wall -Wextra
CFLAGS_DEBUG   = $(CFLAGS) -g -O0
CFLAGS_RELEASE = $(CFLAGS) -O2 -DNDEBUG

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) 
OBJ_FILES = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_FILES:.c=.o))

.PHONY: all build release debug clean

all: build

# Build (default target)
build: $(OUT_NAME)

$(OUT_NAME): $(OBJ_FILES)
	mkdir -p $(OUT_DIR_BUILD)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Release build
release: $(OUT_DIR_RELEASE)/$(OUT_NAME)

$(OUT_DIR_RELEASE)/$(OUT_NAME): $(SRC)
	mkdir -p $(OUT_DIR_RELEASE)
	$(CC) $(CFLAGS_RELEASE) -o $@ $^

# Debug build
debug: $(OUT_DIR_BUILD)/$(OUT_NAME)_debug

$(OUT_DIR_BUILD)/$(OUT_NAME)_debug: $(SRC)
	mkdir -p $(OUT_DIR_BUILD)
	$(CC) $(CFLAGS_DEBUG) -o $@ $^

# Clean up
clean:
	rm -rf $(OUT_DIR_BUILD) $(OUT_DIR_RELEASE)
