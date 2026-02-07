CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = corso_demo
OBJECTS = Main.o Studente.o Corso.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp Corso.hpp Studente.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

Studente.o: Studente.cpp Studente.hpp
	$(CXX) $(CXXFLAGS) -c Studente.cpp

Corso.o: Corso.cpp Corso.hpp Studente.hpp
	$(CXX) $(CXXFLAGS) -c Corso.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) corso_output.txt
