CXX = g++
CXXFLAGS = -Wall -std=c++11 -lm

TARGET = corriere_demo
OBJECTS = Main.o CorrierEspresso.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp CorrierEspresso.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

CorrierEspresso.o: CorrierEspresso.cpp CorrierEspresso.hpp
	$(CXX) $(CXXFLAGS) -c CorrierEspresso.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
