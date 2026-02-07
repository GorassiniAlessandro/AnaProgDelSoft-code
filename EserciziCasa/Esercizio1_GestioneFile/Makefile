CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = esercizio1
OBJECTS = Main.o Persona.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp Persona.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

Persona.o: Persona.cpp Persona.hpp
	$(CXX) $(CXXFLAGS) -c Persona.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) output.txt
