# Makefile for Memory Leak Detective
# COS 110 - Pointers and Dynamic Memory

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -pedantic
TARGET = leak_detective

# Source files
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the programme
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Cleaned up compiled files"

# Run the programme
run: $(TARGET)
	./$(TARGET)

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Display help
help:
	@echo "Available targets:"
	@echo "  make          - Build the programme"
	@echo "  make run      - Build and run the programme"
	@echo "  make clean    - Remove compiled files"
	@echo "  make memcheck - Run with valgrind to check for memory leaks"
	@echo "  make help     - Display this help message"

.PHONY: all clean run memcheck help
