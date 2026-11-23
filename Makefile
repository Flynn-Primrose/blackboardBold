CXX      := g++
CPPFLAGS := -Iheaders -MMD -MP
CXXFLAGS := -Wall -Wextra -g -std=c++20

SRC_DIR := sources
OBJ_DIR := obj
BIN_DIR := bin
TST_DIR := tests

SRCS      := $(wildcard $(SRC_DIR)/*.cpp)
OBJS      := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TSTS      := $(wildcard $(TST_DIR)/*.cpp)
TST_OBJ_DIR := $(OBJ_DIR)/tests
TST_OBJS    := $(patsubst $(TST_DIR)/%.cpp,$(TST_OBJ_DIR)/%.o,$(TSTS))
TEST_BIN    := $(BIN_DIR)/run_tests.exe
LIB       := $(BIN_DIR)/blackboardBold.lib

# Platform-specific commands, defined once
ifeq ($(OS),Windows_NT)
    MKDIR = if not exist "$(subst /,\,$@)" mkdir "$(subst /,\,$@)"
    CLEAN = -rmdir /s /q $(OBJ_DIR) & -rmdir /s /q $(BIN_DIR)
else
    MKDIR = mkdir -p $@
    CLEAN = rm -rf $(OBJ_DIR) $(BIN_DIR)
endif

all: library tests

library: $(LIB)
tests: $(TEST_BIN)

# Archive the library
$(LIB): $(OBJS) | $(BIN_DIR)
	ar rcs $@ $^

# Compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Link all test objects + the library into one executable
$(TEST_BIN): $(TST_OBJS) $(LIB) | $(BIN_DIR)
	$(CXX) $(TST_OBJS) $(LIB) -o $@

# Compile each test file to an object
$(TST_OBJ_DIR)/%.o: $(TST_DIR)/%.cpp | $(TST_OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Build and run
test: $(TEST_BIN)
	./$(TEST_BIN)

# Create directories on demand (add the new one)
$(OBJ_DIR) $(BIN_DIR) $(TST_OBJ_DIR):
	$(MKDIR)

clean:
	$(CLEAN)

.PHONY: all library tests test clean

# Pull in auto-generated header dependency files (silently skip if absent)
-include $(OBJS:.o=.d) $(TST_OBJS:.o=.d)
