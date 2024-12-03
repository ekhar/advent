CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = solution
SRC = main.cpp
INPUT = input.txt

all: build run

build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all build run clean
