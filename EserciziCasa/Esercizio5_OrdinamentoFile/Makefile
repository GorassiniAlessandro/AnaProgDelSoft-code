CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = sort_demo
OBJECTS = Main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) sorted.txt
