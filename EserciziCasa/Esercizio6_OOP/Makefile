CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = rettangoli_demo
OBJECTS = Main.o Rettangolo.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp Rettangolo.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

Rettangolo.o: Rettangolo.cpp Rettangolo.hpp
	$(CXX) $(CXXFLAGS) -c Rettangolo.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
