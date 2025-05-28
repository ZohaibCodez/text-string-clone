# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Folders
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BIN_DIR = bin

# Files
TARGET = $(BIN_DIR)/text_demo
SRCS = $(SRC_DIR)/text.cpp $(TEST_DIR)/main.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $^ -o $@

# Clean build artifacts
clean:
	rm -rf $(BIN_DIR) *.o $(SRC_DIR)/*.o $(TEST_DIR)/*.o

# Run
run: all
	./$(TARGET)
