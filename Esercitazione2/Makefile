CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = DriverVettori.exe
OBJ = Vettori3D.o DriverVettori.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

Vettori3D.o: Vettori3D.cpp Vettori3D.hpp
	$(CXX) $(CXXFLAGS) -c Vettori3D.cpp

DriverVettori.o: DriverVettori.cpp Vettori3D.hpp
	$(CXX) $(CXXFLAGS) -c DriverVettori.cpp

clean:
	del $(OBJ) $(TARGET)
