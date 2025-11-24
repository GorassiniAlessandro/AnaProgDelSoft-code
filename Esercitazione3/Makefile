# Nome dell'eseguibile
TARGET = polinomio

# Compilatore
CXX = g++

# Opzioni di compilazione
CXXFLAGS = -Wall -Wextra -std=c++11

# File oggetto necessari
OBJS = Poli.o DriverPoli.o

# Regola principale
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regola per compilare Poli.cpp
Poli.o: Poli.cpp Poli.hpp
	$(CXX) $(CXXFLAGS) -c Poli.cpp

# Regola per compilare DriverPoli.cpp
DriverPoli.o: DriverPoli.cpp Poli.hpp
	$(CXX) $(CXXFLAGS) -c DriverPoli.cpp

# Pulizia dei file compilati
clean:
	rm -f $(OBJS) $(TARGET)

# Pulizia completa con backup
cleanall:
	rm -f $(OBJS) $(TARGET) *~ 