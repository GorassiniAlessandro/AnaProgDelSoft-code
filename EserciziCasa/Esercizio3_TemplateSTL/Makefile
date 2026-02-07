CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = maxcontainer_demo
OBJECTS = Main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp MaxInContainer.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
