# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -Iheaders

# Directories
SRC_DIR = sources
OBJ_DIR = obj
BIN_DIR = bin
XPL_DIR = examples
TST_DIR = tests

# Find all source files in the SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Create a list of object files by replacing .cpp with .o
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Find all example files in the XPL_DIR
XPLS = $(wildcard $(XPL_DIR)/*.cpp)

# Find all test files in the TST_DIR
TSTS = $(wildcard $(TST_DIR)/*.cpp)

# Create a list of executible files by replacing .cpp with .exe
EXES = $(patsubst $(XPL_DIR)/%.cpp, $(BIN_DIR)/%.exe, $(XPLS), $(BIN_DIR)/%.exe)

# Target library files

LIBS = $(BIN_DIR)/tulliotools2.lib

# Default target
all: library tests examples

tests: $(TSTS)

examples: $(EXES)

library: $(LIBS)

# Compile Tests
$(BIN_DIR)/%.exe: $(TST_DIR)/%.cpp
ifeq ($(OS),Windows_NT)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	@mkdir -p $(BIN_DIR)
endif
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIBS)

# Compile Example
$(BIN_DIR)/%.exe: $(XPL_DIR)/%.cpp
ifeq ($(OS),Windows_NT)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	@mkdir -p $(BIN_DIR)
endif
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIBS)

# Linking
$(TARGET): $(OBJS)
ifeq ($(OS),Windows_NT)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	@mkdir -p $(BIN_DIR)
endif
	ar rcs $@ $^

# Compile Objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
else
	@mkdir -p $(OBJ_DIR)
endif
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

# Clean up
clean:
ifeq ($(OS),Windows_NT)
	del $(OBJ_DIR) $(BIN_DIR)
else
	rm -rf $(OBJ_DIR) $(BIN_DIR)
endif
	

.PHONY: all clean
