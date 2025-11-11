CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = DriverOrario.exe
OBJ = Orario.o DriverOrario.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

Orario.o: Orario.cpp Orario.hpp
	$(CXX) $(CXXFLAGS) -c Orario.cpp

DriverOrario.o: DriverOrario.cpp Orario.hpp
	$(CXX) $(CXXFLAGS) -c DriverOrario.cpp

clean:
	del $(OBJ) $(TARGET)

.PHONY: all clean
