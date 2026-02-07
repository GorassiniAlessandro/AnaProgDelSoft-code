CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = stack_demo
OBJECTS = Main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp Stack.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
