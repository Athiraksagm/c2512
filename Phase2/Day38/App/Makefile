# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Iinclude
DEBUG_OPTIONS = -tui
# Target executable
TARGET = app.out

# Directories
SRCDIR = source
OBJDIR = build
HEADDIR = include

# Detect all source files and create corresponding object file paths
SRCS = $(wildcard $(SRCDIR)/*.cpp) main.cpp
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) $^ -o $@ 

# Build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the Build directory exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean up object files and the executable
clean:
	@echo "\nCleaning up..."
	@rm -rf $(OBJDIR)
	@rm -f $(TARGET)

# Print source and object files (optional debugging targets)
print:
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"

# Run the built executable
run: all
	@echo "\nRunning $(TARGET)..."
	./$(TARGET)

# Debug the executable
debug: all
	@echo "\nDebugging $(TARGET)..."
	gdb $(DEBUG_OPTIONS) ./$(TARGET)
