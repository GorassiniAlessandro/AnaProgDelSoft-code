CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = stazione_demo
OBJECTS = Main.o StazioneSciistica.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

Main.o: Main.cpp StazioneSciistica.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

StazioneSciistica.o: StazioneSciistica.cpp StazioneSciistica.hpp
	$(CXX) $(CXXFLAGS) -c StazioneSciistica.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
