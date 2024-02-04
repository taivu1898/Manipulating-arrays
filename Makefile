CC = clang
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS = -shared

SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
LIB_FILE = $(LIB_DIR)/libio_array.so

TARGET = add_element

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ_FILES) $(LIB_FILE)
	$(CC) $(CFLAGS) -o $@ $(SRC_DIR)/$@.c -L$(LIB_DIR) -lio_array -Wl,-rpath,$(LIB_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_FILE): $(OBJ_FILES) | $(LIB_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) $(TARGET)