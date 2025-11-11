CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = DriverConto.exe
OBJ = ContoCorrente.o DriverConto.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

ContoCorrente.o: ContoCorrente.cpp ContoCorrente.hpp
	$(CXX) $(CXXFLAGS) -c ContoCorrente.cpp

DriverConto.o: DriverConto.cpp ContoCorrente.hpp
	$(CXX) $(CXXFLAGS) -c DriverConto.cpp

clean:
	del $(OBJ) $(TARGET)

.PHONY: all clean
